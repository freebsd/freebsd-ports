Drop once FreeBSD 10.* is EOL as USE_GCC defaultso to >= 6 since 2017-09-10.

https://github.com/harfbuzz/harfbuzz/issues/1338

--- src/test-ot-color.cc.orig	2018-10-30 05:40:14 UTC
+++ src/test-ot-color.cc
@@ -23,7 +23,7 @@
  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
  */
 
-#include "hb.h"
+#include "hb.hh"
 #include "hb-ot.h"
 
 #include "hb-ft.h"
