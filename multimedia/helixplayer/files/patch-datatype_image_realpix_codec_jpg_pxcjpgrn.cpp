--- ./datatype/image/realpix/codec/jpg/pxcjpgrn.cpp.orig	Fri Jul  9 03:51:18 2004
+++ ./datatype/image/realpix/codec/jpg/pxcjpgrn.cpp	Mon Sep 13 11:43:45 2004
@@ -71,7 +71,7 @@
 // pxcomlib
 #include "rpcodec.h"
 #include "gstring.h"
-#include "glist.h"
+#include "../../../common/pub/glist.h" // May conflict with HDF's <glist.h>
 #include "pxrndcod.h"
 #include "pxutil.h"
 #include "pxmapmgr.h"
