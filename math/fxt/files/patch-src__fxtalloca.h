--- ./src/fxtalloca.h.orig	2010-10-26 21:49:13.000000000 +0200
+++ ./src/fxtalloca.h	2010-10-26 21:49:58.000000000 +0200
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
 #define ALLOCA(Type, v, n)  Type *v = (Type *)alloca((n)*sizeof(Type))
 #endif
 
