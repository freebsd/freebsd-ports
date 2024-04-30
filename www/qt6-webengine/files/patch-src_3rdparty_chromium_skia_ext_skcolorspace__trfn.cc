--- src/3rdparty/chromium/skia/ext/skcolorspace_trfn.cc.orig	2023-08-17 07:33:31 UTC
+++ src/3rdparty/chromium/skia/ext/skcolorspace_trfn.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <cmath>
+
 #include "skia/ext/skcolorspace_trfn.h"
 
 #include <cmath>
