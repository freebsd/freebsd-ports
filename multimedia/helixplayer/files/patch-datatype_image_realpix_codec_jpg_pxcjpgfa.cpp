--- ./datatype/image/realpix/codec/jpg/pxcjpgfa.cpp.orig	Fri Jul  9 03:51:18 2004
+++ ./datatype/image/realpix/codec/jpg/pxcjpgfa.cpp	Mon Sep 13 12:07:39 2004
@@ -70,7 +70,7 @@
 // pxcomlib
 #include "pxffmcod.h"
 #include "pxrndcod.h"
-#include "glist.h"
+#include "../../../common/pub/glist.h" // May conflict with HDF's <glist.h>
 #include "gstring.h"
 #include "pxmapmgr.h"
 #include "pxparse.h"
