--- chrome/common/child_process_logging.h.orig	2011-11-22 01:03:45.000000000 +0200
+++ chrome/common/child_process_logging.h	2011-11-22 01:03:57.000000000 +0200
@@ -30,7 +30,7 @@
 
 namespace child_process_logging {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // These are declared here so the crash reporter can access them directly in
 // compromised context without going through the standard library.
 extern char g_active_url[];
