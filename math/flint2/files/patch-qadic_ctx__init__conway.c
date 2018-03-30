Workaround for https://github.com/wbhart/flint2/issues/460

--- qadic/ctx_init_conway.c.orig	2018-03-30 04:28:36 UTC
+++ qadic/ctx_init_conway.c
@@ -19,7 +19,7 @@
 
 int flint_conway_polynomials [] = {
 #if !defined( _MSC_VER)
-#include "../build/CPimport.h"
+#include "../../.build/CPimport.h"
 #else
 #include "CPimport.h"
 #endif
