--- ./kmlf.h	Thu Sep  2 11:18:38 2004
+++ ../magicolor2430DL-1.1.0-new/./kmlf.h	Thu Jul 28 18:56:32 2005
@@ -38,6 +38,8 @@
 
 #ifdef __linux
 #define KM_FOLDER		"/usr/local/KONICA_MINOLTA"
+#elif defined(__FreeBSD__)
+#define KM_FOLDER		"/usr/local/share/KONICA_MINOLTA"
 #else
 #define KM_FOLDER		"/Library/Printers/KONICA_MINOLTA"
 #endif
