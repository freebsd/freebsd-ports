--- chrome/common/child_process_logging.h.orig	2012-01-18 11:13:17.000000000 +0200
+++ chrome/common/child_process_logging.h	2012-01-29 15:30:03.000000000 +0200
@@ -33,7 +33,7 @@
 
 namespace child_process_logging {
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // These are declared here so the crash reporter can access them directly in
 // compromised context without going through the standard library.
 extern char g_active_url[];
