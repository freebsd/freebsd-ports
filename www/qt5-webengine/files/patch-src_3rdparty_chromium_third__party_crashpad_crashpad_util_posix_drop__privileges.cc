--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/drop_privileges.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/drop_privileges.cc
@@ -23,7 +23,7 @@ void DropPrivileges() {
   gid_t gid = getgid();
   uid_t uid = getuid();
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Based on the POSIX.1-2008 2013 edition documentation for setreuid() and
   // setregid(), setreuid() and setregid() alone should be sufficient to drop
   // privileges. The standard specifies that the saved ID should be set to the
