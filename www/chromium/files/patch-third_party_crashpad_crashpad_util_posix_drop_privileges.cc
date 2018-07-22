--- third_party/crashpad/crashpad/util/posix/drop_privileges.cc.orig	2018-07-19 19:50:51.829905000 +0200
+++ third_party/crashpad/crashpad/util/posix/drop_privileges.cc	2018-07-19 19:51:04.660155000 +0200
@@ -23,7 +23,7 @@
   gid_t gid = getgid();
   uid_t uid = getuid();
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Based on the POSIX.1-2008 2013 edition documentation for setreuid() and
   // setregid(), setreuid() and setregid() alone should be sufficient to drop
   // privileges. The standard specifies that the saved ID should be set to the
