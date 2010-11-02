--- src/pam_mount.c.orig	2010-08-10 01:07:35.000000000 +0200
+++ src/pam_mount.c	2010-10-14 18:04:54.000000000 +0200
@@ -39,6 +39,8 @@
 
 #if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 #	define CONFIGFILE "/etc/pam_mount.conf.xml"
+#elif defined(__FreeBSD__)
+#  define CONFIGFILE "%%PREFIX%%/etc/security/pam_mount.conf.xml"
 #else
 #	define CONFIGFILE "/etc/security/pam_mount.conf.xml"
 #endif
