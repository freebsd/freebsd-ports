--- gsl/wrappers.h.orig	Thu Jul 22 11:33:38 2004
+++ gsl/wrappers.h	Thu Aug  5 11:10:31 2004
@@ -70,7 +70,7 @@
 #define CONCAT3(a,b,c) CONCAT3x(a,b,c)
 
 #ifndef DONT_USE_ALLOCA
-#include <malloc.h>
+#include <stdlib.h>
 #define LOCALARRAY(type, x, len)  type * x = ( type *) alloca(sizeof( type ) * (len))
 #else
 #define LOCALARRAY(type, x, len)  type x [(len)] 
