--- xcdroast.h.orig	Tue Aug 14 00:15:43 2001
+++ xcdroast.h	Tue Aug 14 00:46:08 2001
@@ -89,14 +89,14 @@
 #define SAVEMASTERTRACK "mkisofs.out"
 
 /* default paths/configfile */
-#define PREFIX "/usr/local"
+#define PREFIX "%%PREFIX%%"
 #define LIBDIR "lib/xcdroast-0.98"
 #define CONFIGDIR "~/.xcdroast"
 #define CONFFILE "xcdr098.cfg"
 #define LOGFILE "xcdr098.log"
 #define ISOOPTFILE "isoopt.cfg"
 #define ISOHEADERFILE "isoheader.cfg"
-#define ROOTCONFIG "/etc/xcdroast.conf"
+#define ROOTCONFIG "%%PREFIX%%/etc/xcdroast.conf"
 
 /* language stuff*/
 #define MAXENTRIES 512 
