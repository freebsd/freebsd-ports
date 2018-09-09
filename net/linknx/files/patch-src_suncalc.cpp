In file included from suncalc.cpp:47:
    /usr/include/c++/v1/math.h:733:39: error: no member named 'fabsf' in the global
          namespace; did you mean simply 'fabsf'?
          abs(float __lcpp_x) _NOEXCEPT {return ::fabsf(__lcpp_x);}
                                                ^~

--- src/suncalc.cpp.orig	2018-08-25 18:51:49 UTC
+++ src/suncalc.cpp
@@ -25,8 +25,6 @@
 #include "suncalc.h"
 #include "services.h"
 
-namespace suncalc
-{
 
 /*
 SUNRISET.C - computes Sun rise/set times, start/end of twilight, and
@@ -49,6 +47,9 @@ Released to the public domain by Paul Schlyter, Decemb
 #include <stdlib.h>
 #include <getopt.h>
 #include <string.h>
+
+namespace suncalc
+{
 
 /* A macro to compute the number of days elapsed since 2000 Jan 0.0 */
 /* (which is equal to 1999 Dec 31, 0h UT)                           */
