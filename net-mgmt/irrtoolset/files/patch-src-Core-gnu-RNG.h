--- src/Core/gnu/RNG.h.orig	2002-03-27 12:32:59.000000000 +0100
+++ src/Core/gnu/RNG.h
@@ -21,18 +21,19 @@ Foundation, 59 Temple Place - Suite 330,
 #pragma interface
 #endif
 
+#include <sys/types.h>
 #include <assert.h>
 #include <math.h>
-#include <_G_config.h>
+#include <config.h>
 
 union PrivateRNGSingleType {		   	// used to access floats as unsigneds
     float s;
-    _G_uint32_t u;
+    uint32_t u;
 };
 
 union PrivateRNGDoubleType {		   	// used to access doubles as unsigneds
     double d;
-    _G_uint32_t u[2];
+    uint32_t u[2];
 };
 
 //
@@ -46,7 +47,7 @@ public:
     //
     // Return a long-words word of random bits
     //
-    virtual _G_uint32_t asLong() = 0;
+    virtual uint32_t asLong() = 0;
     virtual void reset() = 0;
     //
     // Return random bits converted to either a float or a double
