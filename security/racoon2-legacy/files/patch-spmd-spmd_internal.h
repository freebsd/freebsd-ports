--- spmd/spmd_internal.h.orig	2008-07-06 11:41:36.000000000 +0900
+++ spmd/spmd_internal.h	2009-03-30 13:35:24.000000000 +0900
@@ -35,7 +35,7 @@
 
 extern int spmd_foreground;
 
-#define RACOON2_CONFIG_FILE SYSCONFDIR"/racoon2.conf"
+#define RACOON2_CONFIG_FILE RACOON_CONF
 
 #if defined(HAVE_NSSWITCH_CONF)
 # define NSSWITCH_CONF_FILE "/etc/nsswitch.conf"
