--- src/Colourscale.cc.orig	Tue Oct 15 00:12:17 2002
+++ src/Colourscale.cc	Tue Oct 15 00:15:30 2002
@@ -18,7 +18,9 @@
 */
 #include "Colourscale.h"
 
-Colourscale :: Colourscale( int ts=64, CScale_t tcs=CS_BL_RAINBOW )
+using namespace std;
+
+Colourscale :: Colourscale( int ts, CScale_t tcs )
 {
 	n = 0;
 	mindat = 0;
