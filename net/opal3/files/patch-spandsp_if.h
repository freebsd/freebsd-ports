--- plugins/fax/fax_spandsp/spandsp_util/spandsp_if.h.orig	2009-08-30 02:52:53.000000000 +0400
+++ plugins/fax/fax_spandsp/spandsp_util/spandsp_if.h	2009-08-30 02:53:00.000000000 +0400
@@ -24,6 +24,11 @@
  */
 
 extern "C" {
+#undef __cplusplus
+#undef _MACHINE__STDINT_H_
+#include <machine/_stdint.h>
+#define __cplusplus
+
 #include "spandsp.h"
 };
 
