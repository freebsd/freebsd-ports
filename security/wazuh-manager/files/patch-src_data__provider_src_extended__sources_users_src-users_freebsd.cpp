--- /dev/null	2026-01-13 23:07:27.483265000 +0000
+++ src/data_provider/src/extended_sources/users/src/users_freebsd.cpp	2026-01-13 22:53:15.807751000 +0000
@@ -0,0 +1,103 @@
+/* Copyright (C) 2015, Wazuh Inc.
+ * All rights reserved.
+ *
+ * This program is free software; you can redistribute it
+ * and/or modify it under the terms of the GNU General Public
+ * License (version 2) as published by the FSF - Free Software
+ * Foundation.
+ */
+
+#include <unistd.h>
+#include <set>
+#include <string>
+#include <map>
+#include <memory>
+
+#include "users_freebsd.hpp"
+#include "passwd_wrapper.hpp"
+
+constexpr size_t MAX_GETPW_R_BUF_SIZE = 16 * 1024;
+
+UsersProvider::UsersProvider(
+    std::shared_ptr<IPasswdWrapperFreeBSD> passwdWrapper)
+    : m_passwdWrapper(std::move(passwdWrapper)) {}
+
+UsersProvider::UsersProvider()
+    : m_passwdWrapper(std::make_shared<PasswdWrapperFreeBSD>()) {}
+
+nlohmann::json UsersProvider::collect(bool include_remote)
+{
+    return collectWithConstraints({}, {}, include_remote);
+}
+
+nlohmann::json UsersProvider::collectWithConstraints(const std::set<std::string>& usernames,
+                                                     const std::set<uid_t>& uids,
+                                                     bool include_remote)
+{
+//    if (include_remote)
+//    {
+//        return collectRemoteUsers(usernames, uids);
+//    }
+
+    return collectUsers(usernames, uids);
+}
+
+nlohmann::json UsersProvider::genUserJson(const struct passwd* pwd, bool include_remote)
+{
+    nlohmann::json r;
+    r["uid"] = pwd->pw_uid;
+    r["gid"] = pwd->pw_gid;
+    r["uid_signed"] = static_cast<int32_t>(pwd->pw_uid);
+    r["gid_signed"] = static_cast<int32_t>(pwd->pw_gid);
+
+    r["username"] = (pwd->pw_name != nullptr) ? pwd->pw_name : "";
+    r["description"] = (pwd->pw_gecos != nullptr) ? pwd->pw_gecos : "";
+    r["directory"] = (pwd->pw_dir != nullptr) ? pwd->pw_dir : "";
+    r["shell"] = (pwd->pw_shell != nullptr) ? pwd->pw_shell : "";
+
+    r["pid_with_namespace"] = "0";
+    r["include_remote"] = static_cast<int>(include_remote);
+
+    return r;
+}
+
+nlohmann::json UsersProvider::collectUsers(const std::set<std::string>& usernames,
+                                                 const std::set<uid_t>& uids)
+{
+    nlohmann::json results = nlohmann::json::array();
+
+    size_t bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
+
+    if (bufsize > MAX_GETPW_R_BUF_SIZE)
+    {
+        bufsize = MAX_GETPW_R_BUF_SIZE;
+    }
+
+    auto buf = std::make_unique<char[]>(bufsize);
+
+    struct passwd pwd;
+    struct passwd* pwd_results
+    {
+        nullptr
+    };
+
+    m_passwdWrapper->setpwent();
+
+    while (m_passwdWrapper->getpwent_r(&pwd, buf.get(), bufsize, &pwd_results) == 0 && pwd_results != nullptr)
+    {
+        if (!usernames.empty() && usernames.find(pwd_results->pw_name) == usernames.end())
+        {
+            continue;
+        }
+        else if (!uids.empty() && uids.find(pwd_results->pw_uid) == uids.end())
+        {
+            continue;
+        }
+
+        results.push_back(genUserJson(pwd_results, true));
+    }
+
+    m_passwdWrapper->endpwent();
+
+    return results;
+}
