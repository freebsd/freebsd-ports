--- hpp/constant.hpp.orig	Fri Jan  7 21:15:51 2005
+++ hpp/constant.hpp	Fri Jan  7 21:17:02 2005
@@ -21,7 +21,7 @@
 #   ifdef __LINUX__
 #      define OsType      "/LNX"
 #   elif defined(__FreeBSD__)
-#      define OsType      "/FBSD"
+#      define OsType      "/BSD"
 #   elif defined(sun)
 #      define OsType      "/SUN"
 #   elif defined(_AIX)
@@ -38,7 +38,7 @@
 #define FTrackProductLo 0xff
 #define FTrackProductHi 0x0c
 #define Copyright      "(C) 1998-2002 Fyodor Ustinov (2:5020/79)"
-#define DefaultConfig  "ftrack.cfg"
+#define DefaultConfig  "/usr/local/etc/ftrack/ftrack.cfg"
 
 #ifdef UNIX
 #define MsgExtension   ".msg"
