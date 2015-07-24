--- src/fxtalloca.h.orig	2012-11-21 18:05:08 UTC
+++ src/fxtalloca.h
@@ -16,13 +16,13 @@
 #if defined  __GNUC__  // GNU compiler
 #define ALLOCA(Type, v, n)  Type v[n]
 #else // __GNUC__
-#include <alloca.h>
+#include <stdlib.h>
 #define ALLOCA(Type, v, n)  Type *v = (Type *)alloca((n)*sizeof(Type))
 #endif // __GNUC__
 
 #ifdef FORCE_ALLOCA_H
 #undef ALLOCA
-#include <alloca.h>
+#include <stdlib.h>
 //#include <stdlib.h>  // for BSD
 #define ALLOCA(Type, v, n)  Type *v = (Type *)alloca((n)*sizeof(Type))
 #endif
