--- css/parser.y.orig	2009-11-21 09:40:45.000000000 +0100
+++ css/parser.y	2009-11-21 09:39:49.000000000 +0100
@@ -398,6 +398,7 @@
 
 %extra_argument { struct css_parser_params *param }
 %include {
+#include <assert.h>
 #include <strings.h>
 #define CSS_INTERNALS
 #include "css/css.h"
