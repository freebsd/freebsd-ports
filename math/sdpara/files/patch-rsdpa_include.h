--- rsdpa_include.h.orig	Sat Nov  2 11:10:59 2002
+++ rsdpa_include.h	Sun Aug  3 09:07:52 2003
@@ -21,13 +21,13 @@
 #include <cstring>
 
 extern "C" {
-#include <f2c.h>
+#include <g2c.h>
 #if NON_ATLAS_SDPA
 #include <blaswrap.h>
 #endif
-#include <fblaswr.h>
 #include <cblas.h>
-#include <clapack.h>
+#include <blas.h>
+#include <lapack.h>
 };
 
 using namespace std;
