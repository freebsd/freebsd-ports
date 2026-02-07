--- xo/res.cxx.orig	2012-12-29 18:51:57 UTC
+++ xo/res.cxx
@@ -43,7 +43,7 @@
 
 #define IS_PARSER
 #include "lres.h"
-#include "res_y.h"
+#include "res_y.hxx"
 
 #define LONG_PRIME_MAX		(LONG_MAX/10)
 #define LONG_PRIME_MAX_REM	(LONG_MAX - LONG_PRIME_MAX*10)
