--- src/fxtalloca.h.orig	2021-10-28 13:13:12 UTC
+++ src/fxtalloca.h
@@ -16,8 +16,8 @@
 #undef ALLOCA
 
 #ifdef FORCE_ALLOCA_H
-#include <alloca.h>
-//#include <stdlib.h>  // for BSD
+//#include <alloca.h>
+#include <stdlib.h>  // for BSD
 #define ALLOCA(Type, v, n)  Type *v = (Type *)alloca((n)*sizeof(Type))
 #else
 #define ALLOCA(Type, v, n)  Type v[n]
