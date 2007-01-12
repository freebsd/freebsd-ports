--- rsdpa_include.h.orig	Sat Nov  2 11:10:59 2002
+++ rsdpa_include.h	Sun Aug  3 09:07:52 2003
@@ -21,13 +21,13 @@
 #include <cstring>
 
 extern "C" {
-#include <f2c.h>
+#include <f2c.h>
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
--- rsdpa_include.h~	Thu Jan 11 16:32:04 2007
+++ rsdpa_include.h	Thu Jan 11 16:32:45 2007
@@ -32,7 +32,7 @@
 // otherwise (for example, BLAS in clapack.tgz), set 1
 //           and edit Makefile to change LAPACK_LIB
 
-#define NON_ATLAS_SDPA 0
+//#define NON_ATLAS_SDPA 0
 
 #include <iostream>
 #include <fstream>
