--- osquery/tables/system/linux/os_version.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/tables/system/linux/os_version.cpp
@@ -22,7 +22,7 @@ namespace xp = boost::xpressive;
 namespace osquery {
 namespace tables {
 
-#ifdef CENTOS
+#if defined(CENTOS) || defined(RHEL)
 const std::string kLinuxOSRelease = "/etc/redhat-release";
 const std::string kLinuxOSRegex =
     "(?P<name>\\w+) .* "
