--- xcdroast.h.orig	Tue Apr 23 20:55:27 2002
+++ xcdroast.h	Fri May 17 17:19:29 2002
@@ -41,12 +41,12 @@
 #define UNAME "/bin/uname -a"
 #define UNAME2 "/usr/bin/uname -a"
 #define CHOWN "/bin/chown"
-#define CHOWN2 "/usr/bin/chown"
+#define CHOWN2 "/usr/sbin/chown"
 #define CHGRP "/bin/chgrp"
 #define CHGRP2 "/usr/bin/chgrp"
 #define CHMOD "/bin/chmod"
 #define CHMOD2 "/usr/bin/chmod"
-#define GROUPADD "/usr/sbin/groupadd"
+#define GROUPADD "/usr/sbin/pw"
 
 #define WAVPLAY "bin/wavplay"
 #define RMTOOL "bin/rmtool"
@@ -59,10 +59,10 @@
    then in $PREFIX (e.g. /usr/bin/cdrecord instead of 
    /usr/local/lib/xcdroast-0.98/bin/cdrecord) */
 
-#define CDRECORD "bin/cdrecord" 
-#define CDDA2WAV "bin/cdda2wav"
-#define READCD "bin/readcd"
-#define MKISOFS "bin/mkisofs"
+#define CDRECORD "%%LOCALBASE%%/bin/cdrecord" 
+#define CDDA2WAV "%%LOCALBASE%%/bin/cdda2wav"
+#define READCD "%%LOCALBASE%%/bin/readcd"
+#define MKISOFS "%%LOCALBASE%%/bin/mkisofs"
 
 /* MINIMUM required versions. Greater versions are now silently
    accepted. 
@@ -70,7 +70,7 @@
    IT WONT WORK WITH LOWER VERSIONS, EVEN WHEN YOU THINK IT DOES! */
  
 #define CDRECORD_VERSION "1.11a19"
-#define MKISOFS_VERSION "1.15a17"
+#define MKISOFS_VERSION "1.15a21"
 #define CDDA2WAV_VERSION "1.11a19"
 #define READCD_VERSION "1.11a19"
 
@@ -116,14 +116,14 @@
 #define SAVEMASTERLIST "xcdrmaster.lst"
 
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
 #define NONROOTBAK "nonrootflags.cfg"
 
 /* language stuff*/
