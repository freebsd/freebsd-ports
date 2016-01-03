--- config.h.orig	2015-09-30 21:11:35 UTC
+++ config.h
@@ -5,10 +5,8 @@
 #define WEBIF_LIVELOG 1
 #define WEBIF_JQUERY 1
 #define TOUCH 1
-//#define WITH_SSL 1
-#if defined(__linux__) || defined(__CYGWIN__)
+#define WITH_SSL 1
 #define HAVE_DVBAPI 1
-#endif
 #define READ_SDT_CHARSETS 1
 #define CLOCKFIX 1
 #define IRDETO_GUESSING 1
@@ -23,18 +21,18 @@
 #define MODULE_MONITOR 1
 
 //#define MODULE_CAMD33 1
-#define MODULE_CAMD35 1
-#define MODULE_CAMD35_TCP 1
+//#define MODULE_CAMD35 1
+//#define MODULE_CAMD35_TCP 1
 #define MODULE_NEWCAMD 1
 #define MODULE_CCCAM 1
 #define MODULE_CCCSHARE 1
-#define MODULE_GBOX 1
-#define MODULE_RADEGAST 1
-#define MODULE_SERIAL 1
+//#define MODULE_GBOX 1
+//#define MODULE_RADEGAST 1
+//#define MODULE_SERIAL 1
 #define MODULE_CONSTCW 1
-#define MODULE_PANDORA 1
-#define MODULE_GHTTP 1
-#define MODULE_SCAM 1
+//#define MODULE_PANDORA 1
+//#define MODULE_GHTTP 1
+//#define MODULE_SCAM 1
 
 #define WITH_CARDREADER 1
 
