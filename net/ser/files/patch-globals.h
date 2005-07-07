
$FreeBSD$

--- globals.h	2004/06/29 19:08:42	1.1
+++ globals.h	2004/06/29 19:30:58
@@ -91,6 +91,7 @@
 /* extern int process_no; */
 extern int sip_warning;
 extern int server_signature;
+extern char* server_name;
 extern char* user;
 extern char* group;
 extern char* chroot_dir;
