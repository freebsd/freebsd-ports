--- components/assist_ranker/ranker_example_util.cc.orig	2018-03-24 12:31:52.824752000 +0100
+++ components/assist_ranker/ranker_example_util.cc	2018-03-24 12:32:32.654498000 +0100
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <math.h>
+
 #include "components/assist_ranker/ranker_example_util.h"
 #include "base/bit_cast.h"
 #include "base/format_macros.h"
