--- spmd/spmd_internal.h~	2007-12-13 19:40:24.000000000 +0900
+++ spmd/spmd_internal.h	2008-08-26 15:10:46.000000000 +0900
@@ -35,7 +35,7 @@
 
 extern int spmd_foreground;
 
-#define RACOON2_CONFIG_FILE SYSCONFDIR"/racoon2/racoon2.conf"
+#define RACOON2_CONFIG_FILE RACOON_CONF
 
 #if defined(HAVE_NSSWITCH_CONF)
 # define NSSWITCH_CONF_FILE "/etc/nsswitch.conf"
