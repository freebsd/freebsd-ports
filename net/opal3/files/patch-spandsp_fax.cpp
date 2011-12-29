--- plugins/fax/fax_spandsp/spandsp_fax.cpp.orig	2011-12-26 21:02:09.000000000 +0000
+++ plugins/fax/fax_spandsp/spandsp_fax.cpp	2011-12-26 21:01:38.000000000 +0000
@@ -42,6 +42,7 @@
  *
  */
 
+#define __STDC_LIMIT_MACROS
 #include <codec/opalplugin.h>
 
 extern "C" {
