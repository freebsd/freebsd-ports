--- ./rkward/rbackend/rembedinternal.cpp.orig	2008-04-10 15:19:08.000000000 +0200
+++ ./rkward/rbackend/rembedinternal.cpp	2009-01-21 10:27:25.000000000 +0100
@@ -87,7 +87,9 @@
 #include "R.h"
 #include "Rinternals.h"
 #include "Rinterface.h"
-#include "Rdevices.h"
+#if (R_VERSION < R_Version(2, 8, 1))
+# include "Rdevices.h"
+#endif
 #include "R_ext/Parse.h"
 
 #ifdef R_2_4
