--- src/headers/paricom.h.orig	Fri Nov  3 13:00:24 2000
+++ src/headers/paricom.h	Wed Sep 29 20:22:41 2004
@@ -86,3 +86,2 @@
 
-#ifdef NOEXP2
 #  ifdef __cplusplus
@@ -92,12 +91,4 @@
 #    define exp2(x) (exp((double)(x)*LOG2))
-#    ifndef __CYGWIN32__
-#      define log2(x) (log((double)(x))/LOG2)
-#    endif
+#    define log2(x) (log((double)(x))/LOG2)
 #  endif
-#else
-  BEGINEXTERN
-    double exp2(double);
-    double log2(double);
-  ENDEXTERN
-#endif
 
