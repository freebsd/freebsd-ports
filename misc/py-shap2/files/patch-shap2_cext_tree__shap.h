--- shap2/cext/tree_shap.h.orig	2023-01-07 02:47:51 UTC
+++ shap2/cext/tree_shap.h
@@ -13,7 +13,7 @@
 #include <ctime>
 #if defined(_WIN32) || defined(WIN32)
     #include <malloc.h>
-#elif defined(__MVS__)
+#elif defined(__MVS__) || defined(__FreeBSD__)
     #include <stdlib.h>
 #else
     #include <alloca.h>
