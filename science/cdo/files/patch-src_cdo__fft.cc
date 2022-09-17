- workaround for: https://code.mpimet.mpg.de/issues/10967
- this fixes compilation failure when std::swap isn't completely defined and it fails with:
- ld: error: undefined hidden symbol: std::__1::enable_if<(is_move_constructible<double>::value) && (is_move_assignable<double>::value), void>::type std::__1::swap<double>(double&, double&)

--- src/cdo_fft.cc.orig	2022-09-17 16:10:25 UTC
+++ src/cdo_fft.cc
@@ -1,5 +1,6 @@
 // This source code is copied from PINGO version 1.5
 
+#include <algorithm>
 #include <cmath>
 
 namespace cdo
