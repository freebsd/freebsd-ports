--- src/basic_fun.cpp.orig	Mon Oct 17 10:22:04 2005
+++ src/basic_fun.cpp	Mon Oct 24 21:08:57 2005
@@ -32,6 +32,9 @@
 #else
 #include <unistd.h>
 #endif
+#if defined(__FreeBSD__)
+    extern "C" char **environ;
+#endif
 
 #include "datatypes.hpp"
 #include "envt.hpp"
@@ -2903,6 +2906,7 @@
 
   BaseGDL* getenv_fun( EnvT* e)
   {
+
     SizeT nParam=e->NParam();
 
     static int environmentIx = e->KeywordIx( "ENVIRONMENT" );
