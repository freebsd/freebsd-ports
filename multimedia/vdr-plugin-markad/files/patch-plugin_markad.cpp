--- plugin/markad.cpp.orig	2012-09-10 12:45:12 UTC
+++ plugin/markad.cpp
@@ -15,8 +15,16 @@
 
 #include "markad.h"
 
+#ifdef PREFIX
+#define DEF_BINDIR PREFIX "/bin"
+#else
 #define DEF_BINDIR "/usr/bin"
+#endif
+#ifdef DATADIR
+#define DEF_LOGODIR DATADIR "/logos"
+#else
 #define DEF_LOGODIR "/var/lib/markad"
+#endif
 
 cPluginMarkAd::cPluginMarkAd(void)
 {
