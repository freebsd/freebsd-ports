--- src/dvbcut.h.orig	2016-11-18 13:31:01 UTC
+++ src/dvbcut.h
@@ -22,11 +22,14 @@
 #define _DVBCUT_DVBCUT_H
 
 #if !defined(DVBCUT_VERSION)
-#define DVBCUT_VERSION "git"
+#define DVBCUT_VERSION  git
 #endif
 
+#define STRINGIFY(x) STRINGIFY1(x)
+#define STRINGIFY1(x) #x
+
 #ifndef VERSION_STRING
-#define VERSION_STRING "dvbcut-" DVBCUT_VERSION
+#define VERSION_STRING "dvbcut-" STRINGIFY(DVBCUT_VERSION)
 #endif
 
 #include <string>
