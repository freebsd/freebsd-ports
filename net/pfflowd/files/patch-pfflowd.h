--- pfflowd.h.orig	2008-05-28 12:04:42.000000000 -0700
+++ pfflowd.h	2008-05-28 12:07:06.000000000 -0700
@@ -21,7 +21,7 @@
 #define PROGVER                 "0.7"
 
 #ifndef PRIVDROP_USER
-# define PRIVDROP_USER          "_pfflowd"
+# define PRIVDROP_USER          "nobody"
 #endif   
 
 #define PRIVDROP_CHROOT_DIR     "/var/empty"
@@ -29,7 +29,12 @@
 #define DEFAULT_INTERFACE       "pfsync0"
 #define LIBPCAP_SNAPLEN         2020    /* Default MTU */
  
-#define _PFSYNC_VER            3
+#ifdef OLD_PFSYNC
+# define _PFSYNC_STATE          pfsync_state
+# define _PFSYNC_VER            2
+#else
+# define _PFSYNC_VER            3
+#endif
 
 /*
  * This is the Cisco Netflow(tm) version 1 packet format
