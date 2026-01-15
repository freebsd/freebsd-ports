--- src/data_provider/src/sysInfoFreeBSD.cpp	2025-11-07 08:46:03.000000000 +0000
+++ src/data_provider/src/sysInfoFreeBSD.cpp	2026-01-14 16:59:37.014537000 +0000
@@ -11,20 +11,33 @@
 #include "sysInfo.hpp"
 #include "cmdHelper.h"
 #include "stringHelper.h"
+#include "timeHelper.h"
 #include "osinfo/sysOsParsers.h"
+#include "sqliteWrapperTemp.h"
+#include "filesystemHelper.h"
 #include <sys/sysctl.h>
 #include <sys/vmmeter.h>
 #include <sys/utsname.h>
 #include "sharedDefs.h"
+#include <regex>
+#include "groups_freebsd.hpp"
+#include "user_groups_freebsd.hpp"
+#include "logged_in_users_freebsd.hpp"
+#include "sudoers_unix.hpp"
+#include "users_freebsd.hpp"
 
+const std::string PKG_DB_PATHNAME {"/var/db/pkg/local.sqlite"};
+const std::string PKG_QUERY {"SELECT p.name, p.maintainer, p.version, p.arch, p.comment, p.flatsize, p.time, v.annotation AS repository,p.origin FROM packages p LEFT JOIN (SELECT pa.package_id, pa.value_id FROM pkg_annotation pa JOIN annotation t ON t.annotation_id = pa.tag_id AND t.annotation = 'repository') pr ON pr.package_id = p.id LEFT JOIN annotation v ON v.annotation_id = pr.value_id;"};
+
 static void getMemory(nlohmann::json& info)
 {
+    constexpr auto vmFree{"vm.stats.vm.v_free_count"};
+    constexpr auto vmInactive{"vm.stats.vm.v_inactive_count"};
     constexpr auto vmPageSize{"vm.stats.vm.v_page_size"};
-    constexpr auto vmTotal{"vm.vmtotal"};
+    constexpr auto vmTotal{"hw.physmem"};
     uint64_t ram{0};
-    const std::vector<int> mib{CTL_HW, HW_PHYSMEM};
     size_t len{sizeof(ram)};
-    auto ret{sysctl(const_cast<int*>(mib.data()), mib.size(), &ram, &len, nullptr, 0)};
+    auto ret{sysctlbyname(vmTotal, &ram, &len, nullptr, 0)};
 
     if (ret)
     {
@@ -52,11 +65,23 @@
         };
     }
 
-    struct vmtotal vmt {};
+    uint64_t freeMem{0};
+    len = sizeof(freeMem);
+    ret = sysctlbyname(vmFree, &freeMem, &len, nullptr, 0);
 
-    len = sizeof(vmt);
+    if (ret)
+    {
+        throw std::system_error
+        {
+            ret,
+            std::system_category(),
+            "Error reading free memory size."
+        };
+    }
 
-    ret = sysctlbyname(vmTotal, &vmt, &len, nullptr, 0);
+    uint64_t inactiveMem{0};
+    len = sizeof(inactiveMem);
+    ret = sysctlbyname(vmInactive, &inactiveMem, &len, nullptr, 0);
 
     if (ret)
     {
@@ -64,11 +89,11 @@
         {
             ret,
             std::system_category(),
-            "Error reading total memory."
+            "Error reading inactive memory size."
         };
     }
 
-    const auto ramFree{(vmt.t_free * pageSize) / KByte};
+    const auto ramFree{(freeMem + inactiveMem) * pageSize / KByte};
     info["ram_free"] = ramFree;
     info["ram_usage"] = 100 - (100 * ramFree / ramTotal);
 }
@@ -96,7 +121,43 @@
 
 static std::string getSerialNumber()
 {
-    return UNKNOWN_VALUE;
+    size_t len{0};
+    auto ret{sysctlbyname("kern.hostuuid", nullptr, &len, nullptr, 0)};
+
+    if (ret)
+    {
+        throw std::system_error
+        {
+            ret,
+            std::system_category(),
+            "Error reading serial number (aka hostuuid)."
+        };
+    }
+
+    const auto spBuff{std::make_unique<char[]>(len + 1)};
+
+    if (!spBuff)
+    {
+        throw std::runtime_error
+        {
+            "Error allocating memory to read the serial number (aka hostuuid)."
+        };
+    }
+
+    ret = sysctlbyname("kern.hostuuid", spBuff.get(), &len, nullptr, 0);
+
+    if (ret)
+    {
+        throw std::system_error
+        {
+            ret,
+            std::system_category(),
+            "Error reading serial number (aka hostuuid)."
+        };
+    }
+
+    spBuff.get()[len] = 0;
+    return std::string{reinterpret_cast<const char*>(spBuff.get())};
 }
 
 static int getCpuCores()
@@ -184,8 +245,12 @@
 
 nlohmann::json SysInfo::getProcessesInfo() const
 {
-    // Currently not supported for this OS
-    return nlohmann::json {};
+    nlohmann::json ret;
+    getProcessesInfo([&ret](nlohmann::json & data)
+    {
+        ret.push_back(data);
+    });
+    return ret;
 }
 
 nlohmann::json SysInfo::getOsInfo() const
@@ -196,11 +261,12 @@
 
     if (!spParser->parseUname(Utils::exec("uname -r"), ret))
     {
-        ret["os_name"] = "BSD";
         ret["os_platform"] = "bsd";
         ret["os_version"] = UNKNOWN_VALUE;
     }
 
+    ret["os_name"] = "FreeBSD";
+
     if (uname(&uts) >= 0)
     {
         ret["sysname"] = uts.sysname;
@@ -215,44 +281,260 @@
 
 nlohmann::json SysInfo::getPorts() const
 {
-    // Currently not supported for this OS.
-    return nlohmann::json {};
-}
+    nlohmann::json ports {};
+    
+    /* USER COMMAND PID FD PROTO LOCAL_ADDRESS FOREIGN_ADDRESS PATH_STATE CONN_STATE */
+    
+#if __FreeBSD_version > 1500045
+    const auto query{exec(R"(sockstat -46qs --libxo json)")};
 
-void SysInfo::getProcessesInfo(std::function<void(nlohmann::json&)> /*callback*/) const
-{
-    // Currently not supported for this OS.
+    if (!query.empty())
+    {
+        nlohmann::json portsjson;
+        portsjson = nlohmann::json::parse(query);
+        auto &portsResult = portsjson["sockstat"]["socket"];
+
+        for(auto &port : portsResult) {
+            std::string localip = "";
+            std::string localport = "";
+            std::string remoteip = "";
+            std::string remoteport = "";
+            std::string statedata = "";
+
+            if (port["pid"] != nullptr) {
+
+                localip = port["local"]["address"];
+                remoteip = port["foreign"]["address"];
+                statedata = port["conn-state"] != nullptr ? (port["conn-state"] == "LISTEN" ? "listening" : Utils::toLowerCase(port["conn-state"])) : statedata;
+
+                if (port["local"]["address"] == "*") {
+                    if ((port["proto"] == "udp4") || (port["proto"] == "tcp4")) {
+                        localip = "0.0.0.0";
+                    } else {
+                        localip = "::";
+                    }
+                }
+
+                localport = port["local"]["port"];
+
+                if (port["foreign"]["address"] == "*") {
+                    if ((port["proto"] == "udp4") || (port["proto"] == "tcp4")) {
+                        remoteip = 0.0.0.0;
+                    } else {
+                        remoteip = "::";
+                    }
+                }
+
+                remoteport = port["foreign"]["port"];
+
+                nlohmann::json portRecord {};
+
+                portRecord["protocol"] = port["proto"];
+                portRecord["local_ip"] = localip;
+                portRecord["local_port"] = localport == "*" ? "0" : localport;
+                portRecord["remote_ip"] = remoteip;
+                portRecord["remote_port"] = remoteport == "*" ? "0" : remoteport;
+                portRecord["tx_queue"] = 0;
+                portRecord["rx_queue"] = 0;
+                portRecord["inode"] = port["fd"];
+                portRecord["state"] = statedata == "??" ? "" : statedata;
+                portRecord["pid"] = port["pid"];
+                portRecord["process"] = port["command"];
+
+                ports.push_back(portRecord);
+             }
+        }
+    }
+#else
+    const auto query{Utils::exec(R"(sockstat -46qs)")};
+
+    if (!query.empty())
+    {
+        const auto lines{Utils::split(Utils::trimToOneSpace(query), '\n')};
+
+        std::regex expression(R"(^(\S+)\s+(\S+)\s+(\d+)\s+(\d+)\s*(\S+)\s+(\S+)\s+(\S+)(?:\s+(\S+))?\s*$)");
+
+        for (const auto& line : lines)
+        {
+            std::smatch data;
+
+            if (std::regex_search(line, data, expression))
+            {
+                std::string localip = "";
+                std::string localport = "";
+                std::string remoteip = "";
+                std::string remoteport = "";
+                std::string statedata = "";
+
+                auto localdata{Utils::split(data[6], ':')};
+                auto remotedata{Utils::split(data[7], ':')};
+
+                if (data[8].matched ) {
+                  statedata = data[8] == "LISTEN" ? "listening" : Utils::toLowerCase(data[8]);
+                }
+
+                localport = localdata[localdata.size() - 1];
+                localdata.pop_back();
+                localip = Utils::join(localdata, ":");
+                remoteport = remotedata[remotedata.size() - 1];
+                remotedata.pop_back();
+                remoteip = Utils::join(remotedata, ":");
+
+                if(localip == "*") {
+                    if((data[5] == "tcp4") || (data[5] == "udp4")) {
+                        localip = "0.0.0.0";
+                    } else {
+                        localip = "::";
+                    }
+                 }
+
+                if(remoteip == "*") {
+                    if((data[5] == "tcp4") || (data[5] == "udp4")) {
+                        remoteip = "0.0.0.0";
+                    } else {
+                        remoteip = "::";
+                    }
+                 }
+
+                if(data[0] != "?") {
+                    nlohmann::json port {};
+
+                    port["protocol"] = data[5];
+                    port["local_ip"] = localip;
+                    port["local_port"] = localport == "*" ? "0" : localport;
+                    port["remote_ip"] = remoteip;
+                    port["remote_port"] = remoteport == "*" ? "0" : remoteport;
+                    port["tx_queue"] = 0;
+                    port["rx_queue"] = 0;
+                    port["inode"] = data[4];
+                    port["state"] = statedata == "??" ? "" : statedata;
+                    port["pid"] = data[3];
+                    port["process"] = data[2];
+
+                    ports.push_back(port);
+                }
+            }
+        }  
+    }
+#endif
+    return ports;
 }
 
-void SysInfo::getPackages(std::function<void(nlohmann::json&)> callback) const
+void SysInfo::getProcessesInfo(std::function<void(nlohmann::json&)> callback) const
 {
-    const auto query{Utils::exec(R"(pkg query -a "%n|%m|%v|%q|%c")")};
+    const auto query{Utils::exec(R"(ps -ax -w -o pid,comm,state,ppid,usertime,systime,user,ruser,svuid,group,rgroup,svgid,pri,nice,ssiz,vsz,rss,pmem,etimes,sid,pgid,tpgid,tty,cpu,nlwp,args --libxo json)")};
 
     if (!query.empty())
     {
-        const auto lines{Utils::split(query, '\n')};
+      nlohmann::json psjson;
+      int64_t agenttime = {Utils::getSecondsFromEpoch()};
+      int64_t etimes{0};
+      psjson = nlohmann::json::parse(query);
+      auto &processes = psjson["process-information"]["process"];
 
-        for (const auto& line : lines)
+      for(auto &process : processes) {
+          std::string user_time{""};
+          std::string system_time{""};
+          etimes = std::stoll(process["elapsed-times"].get<std::string>());
+
+          user_time = process["user-time"].get<std::string>();
+          system_time = process["system-time"].get<std::string>();
+
+          nlohmann::json jsProcessInfo{};
+          jsProcessInfo["pid"]        = process["pid"].get<std::string>();
+          jsProcessInfo["name"]       = process["command"].get<std::string>();
+          jsProcessInfo["state"]      = process["state"].get<std::string>();
+          jsProcessInfo["ppid"]       = process["ppid"].get<std::string>();
+          jsProcessInfo["utime"]      = Utils::timeToSeconds(user_time);
+          jsProcessInfo["stime"]      = Utils::timeToSeconds(system_time);
+          jsProcessInfo["cmd"]        = process["command"].get<std::string>();
+          jsProcessInfo["argvs"]      = process["arguments"].get<std::string>();
+          jsProcessInfo["euser"]      = process["user"].get<std::string>();
+          jsProcessInfo["ruser"]      = process["real-user"].get<std::string>();
+          jsProcessInfo["suser"]      = process["saved-uid"].get<std::string>();
+          jsProcessInfo["egroup"]     = process["group"].get<std::string>();
+          jsProcessInfo["rgroup"]     = process["real-group"].get<std::string>();
+          jsProcessInfo["sgroup"]     = process["saved-gid"].get<std::string>();
+          jsProcessInfo["fgroup"]     = process["group"].get<std::string>();
+          jsProcessInfo["priority"]   = process["priority"].get<std::string>();
+          jsProcessInfo["nice"]       = process["nice"].get<std::string>();
+          jsProcessInfo["size"]       = process["stack-size"].get<std::string>();
+          jsProcessInfo["vm_size"]    = process["virtual-size"].get<std::string>();
+          jsProcessInfo["resident"]   = process["rss"].get<std::string>();
+          //jsProcessInfo["share"]      = process["percent-memory"].get<std::string>();
+          jsProcessInfo["start_time"] = agenttime - etimes;
+          jsProcessInfo["pgrp"]       = process["process-group"].get<std::string>();
+          jsProcessInfo["session"]    = process["sid"].get<std::string>();
+          jsProcessInfo["tgid"]       = process["terminal-process-gid"].get<std::string>();
+          //jsProcessInfo["tty"]        = process["tty"].get<std::string>(); // this field should be TEXT into local.db
+          jsProcessInfo["processor"]  = process["on-cpu"].get<std::string>();
+          jsProcessInfo["nlwp"]       = process["threads"].get<std::string>();
+
+          callback(jsProcessInfo);
+      }
+    }
+}
+
+void SysInfo::getPackages(std::function<void(nlohmann::json&)> callback) const
+{
+    if (Utils::existsRegular(PKG_DB_PATHNAME))
+    {
+        try
         {
-            const auto data{Utils::split(line, '|')};
-            nlohmann::json package;
+            std::shared_ptr<SQLite::IConnection> sqliteConnection = std::make_shared<SQLite::Connection>(PKG_DB_PATHNAME, SQLITE_OPEN_READONLY);
 
-            package["name"] = data[0];
-            package["vendor"] = data[1];
-            package["version"] = data[2];
-            package["install_time"] = UNKNOWN_VALUE;
-            package["location"] = UNKNOWN_VALUE;
-            package["architecture"] = data[3];
-            package["groups"] = UNKNOWN_VALUE;
-            package["description"] = data[4];
-            package["size"] = 0;
-            package["priority"] = UNKNOWN_VALUE;
-            package["source"] = UNKNOWN_VALUE;
-            package["format"] = "pkg";
-            // The multiarch field won't have a default value
+            SQLite::Statement stmt
+            {
+                sqliteConnection,
+                PKG_QUERY
+            };
 
-            callback(package);
+            while (SQLITE_ROW == stmt.step())
+            {
+                try
+                {
+                    auto pkg_name{ stmt.column(0) };
+                    auto pkg_maintainer{ stmt.column(1) };
+                    auto pkg_version{ stmt.column(2) };
+                    auto pkg_arch{ stmt.column(3) };
+                    auto pkg_comment{ stmt.column(4) };
+                    auto pkg_flatsize{ stmt.column(5) };
+                    auto pkg_time{ stmt.column(6) };
+                    auto pkg_repository{ stmt.column(7) };
+                    auto pkg_origin{ stmt.column(8) };
+
+                    const auto archdata{Utils::split(pkg_arch->value(std::string{}), ':')};
+                    const auto sectiondata{Utils::split(pkg_origin->value(std::string{}), '/')};
+
+                    nlohmann::json package;
+
+                    package["name"] = pkg_name->value(std::string{});
+                    package["vendor"] = pkg_maintainer->value(std::string{});
+                    package["version"] = pkg_version->value(std::string{});
+                    package["install_time"] = pkg_time->value(std::string{});
+                    package["location"] = UNKNOWN_VALUE;
+                    package["architecture"] = archdata[2];
+                    package["groups"] = UNKNOWN_VALUE;
+                    package["description"] = pkg_comment->value(std::string{});
+                    package["size"] = pkg_flatsize->value(uint64_t{});
+                    package["priority"] = UNKNOWN_VALUE;
+                    package["source"] = pkg_repository->value(std::string{});
+                    package["section"] = sectiondata[0];
+                    package["format"] = "pkg";
+                    // The multiarch field won't have a default value
+
+                    callback(package);
+                }
+                catch (const std::exception& e)
+                {
+                    std::cerr << e.what() << std::endl;
+                }
+            }
         }
+        catch (const std::exception& e)
+        {
+            std::cerr << e.what() << std::endl;
+        }
     }
 }
 
@@ -264,14 +546,188 @@
 
 nlohmann::json SysInfo::getGroups() const
 {
-    //TODO: Pending implementation.
-    return nlohmann::json();
+    nlohmann::json result;
+    GroupsProvider groupsProvider;
+    UserGroupsProvider userGroupsProvider;
+
+    auto collectedGroups = groupsProvider.collect({});
+
+    for (auto& group : collectedGroups)
+    {
+        nlohmann::json groupItem {};
+
+        groupItem["group_id"] = group["gid"];
+        groupItem["group_name"] = (group.contains("groupname") && !group["groupname"].get<std::string>().empty()) ? group["groupname"] : UNKNOWN_VALUE;
+        groupItem["group_description"] = UNKNOWN_VALUE;
+        groupItem["group_id_signed"] = group["gid_signed"];
+        groupItem["group_uuid"] = UNKNOWN_VALUE;
+        groupItem["group_is_hidden"] = 0;
+
+        std::set<gid_t> gids {static_cast<gid_t>(group["gid"].get<int>())};
+        auto collectedUsersGroups = userGroupsProvider.getUserNamesByGid(gids);
+
+        if (collectedUsersGroups.empty())
+        {
+            groupItem["group_users"] = UNKNOWN_VALUE;
+        }
+        else
+        {
+            std::string usersConcatenated;
+
+            for (const auto& user : collectedUsersGroups)
+            {
+                if (!usersConcatenated.empty())
+                {
+                    usersConcatenated += secondaryArraySeparator;
+                }
+
+                usersConcatenated += user.get<std::string>();
+            }
+
+            groupItem["group_users"] = usersConcatenated;
+        }
+
+        result.push_back(std::move(groupItem));
+
+    }
+
+    return result;
 }
 
 nlohmann::json SysInfo::getUsers() const
 {
-    //TODO: Pending implementation.
-    return nlohmann::json();
+    nlohmann::json result;
+
+    UsersProvider usersProvider;
+    auto collectedUsers = usersProvider.collect();
+
+    LoggedInUsersProvider loggedInUserProvider;
+    auto collectedLoggedInUser = loggedInUserProvider.collect();
+
+    UserGroupsProvider userGroupsProvider;
+
+    for (auto& user : collectedUsers)
+    {
+        nlohmann::json userItem {};
+
+        std::string username = (user.contains("username") && !user["username"].get<std::string>().empty()) ? user["username"] : UNKNOWN_VALUE;
+
+        userItem["user_id"] = user["uid"];
+        userItem["user_full_name"] = user["description"];
+        userItem["user_home"] = user["directory"];
+        userItem["user_is_remote"] = user["include_remote"];
+        userItem["user_name"] = username;
+        userItem["user_shell"] = user["shell"];
+        userItem["user_uid_signed"] = user["uid_signed"];
+        userItem["user_group_id_signed"] = user["gid_signed"];
+        userItem["user_group_id"] = user["gid"];
+
+        std::set<uid_t> uid {static_cast<uid_t>(user["uid"].get<int>())};
+        auto collectedUsersGroups = userGroupsProvider.getGroupNamesByUid(uid);
+
+        if (collectedUsersGroups.empty())
+        {
+            userItem["user_groups"] = UNKNOWN_VALUE;
+        }
+        else
+        {
+            std::string accumGroups;
+
+            for (const auto& group : collectedUsersGroups)
+            {
+                if (!accumGroups.empty())
+                {
+                    accumGroups += secondaryArraySeparator;
+                }
+
+                accumGroups += group.get<std::string>();
+            }
+
+            userItem["user_groups"] = accumGroups;
+        }
+
+        // Only in windows
+        userItem["user_type"] = UNKNOWN_VALUE;
+
+        // Macos or windows
+        userItem["user_uuid"] = UNKNOWN_VALUE;
+
+        // Macos
+        userItem["user_is_hidden"] = 0;
+        userItem["user_created"] = 0;
+        userItem["user_auth_failed_count"] = 0;
+        userItem["user_auth_failed_timestamp"] = 0;
+
+        auto matched = false;
+        auto lastLogin = 0;
+
+        userItem["host_ip"] = UNKNOWN_VALUE;
+
+        //TODO: Avoid this iteration, move logic to LoggedInUsersProvider
+        for (auto& item : collectedLoggedInUser)
+        {
+            // By default, user is not logged in.
+            userItem["login_status"] = 0;
+
+            // tty,host,time and pid can take more than one value due to different logins.
+            if (item["user"] == username)
+            {
+                matched = true;
+                userItem["login_status"] = 1;
+
+                auto newDate = item["time"].get<int32_t>();
+
+                if (newDate > lastLogin)
+                {
+                    lastLogin = newDate;
+                    userItem["user_last_login"] = newDate;
+                    userItem["login_tty"] = item["tty"].get<std::string>();
+                    userItem["login_type"] = item["type"].get<std::string>();
+                    userItem["process_pid"] = item["pid"].get<int32_t>();
+                }
+
+                const auto& hostStr = item["host"].get_ref<const std::string&>();
+
+                if (!hostStr.empty())
+                {
+                    userItem["host_ip"] = userItem["host_ip"].get<std::string>() == UNKNOWN_VALUE
+                                          ? hostStr
+                                          : (userItem["host_ip"].get<std::string>() + primaryArraySeparator + hostStr);
+                }
+            }
+        }
+
+        if (!matched)
+        {
+            userItem["login_status"] = 0;
+            userItem["login_tty"] = UNKNOWN_VALUE;
+            userItem["login_type"] = UNKNOWN_VALUE;
+            userItem["process_pid"] = 0;
+            userItem["user_last_login"] = 0;
+        }
+
+        matched = false;
+
+        if (!matched)
+        {
+            userItem["user_password_expiration_date"] = 0;
+            userItem["user_password_hash_algorithm"] = UNKNOWN_VALUE;
+            userItem["user_password_inactive_days"] = 0;
+            userItem["user_password_last_change"] = 0;
+            userItem["user_password_max_days_between_changes"] = 0;
+            userItem["user_password_min_days_between_changes"] = 0;
+            userItem["user_password_status"] = UNKNOWN_VALUE;
+            userItem["user_password_warning_days_before_expiration"] = 0;
+        }
+
+
+        // By default, user is not sudoer.
+        userItem["user_roles"] = UNKNOWN_VALUE;
+
+        result.push_back(std::move(userItem));
+    }
+
+    return result;
 }
 
 nlohmann::json SysInfo::getServices() const
