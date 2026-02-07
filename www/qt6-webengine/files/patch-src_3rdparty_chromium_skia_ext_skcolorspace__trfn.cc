--- src/3rdparty/chromium/skia/ext/skcolorspace_trfn.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/skia/ext/skcolorspace_trfn.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <cmath>
+
 #include "skia/ext/skcolorspace_trfn.h"
 
 #include <array>
