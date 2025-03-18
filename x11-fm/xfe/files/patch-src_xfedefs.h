--- src/xfedefs.h.orig	2025-01-24 15:19:54 UTC
+++ src/xfedefs.h
@@ -351,6 +351,9 @@ enum
 // Macro to add parentheses before and after a given string
 #define PARS(s)    ((FXString)" (" + (s) + (FXString)")")
 
+#if defined(__FreeBSD__)
+#define OTHER_PKG    2
+#endif
 
 // Linux specials
 
