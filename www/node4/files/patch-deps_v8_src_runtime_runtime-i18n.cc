--- deps/v8/src/runtime/runtime-i18n.cc.orig	2017-07-11 01:49:24 UTC
+++ deps/v8/src/runtime/runtime-i18n.cc
@@ -22,6 +22,7 @@
 #include "unicode/dtfmtsym.h"
 #include "unicode/dtptngen.h"
 #include "unicode/locid.h"
+#include "unicode/normlzr.h"
 #include "unicode/numfmt.h"
 #include "unicode/numsys.h"
 #include "unicode/rbbi.h"
