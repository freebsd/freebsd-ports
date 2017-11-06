--- third_party/re2/src/util/benchmark.cc.orig	2017-10-06 17:07:48 UTC
+++ third_party/re2/src/util/benchmark.cc
@@ -6,6 +6,7 @@
 #include <stdio.h>
 #include <algorithm>
 #include <chrono>
+#include <stdlib.h>
 
 #include "util/util.h"
 #include "util/flags.h"
