--- src/Colourscale.cc.orig	Thu Jan 16 02:38:50 2003
+++ src/Colourscale.cc	Thu Jan 16 02:39:10 2003
@@ -18,6 +18,8 @@
 */
 #include "Colourscale.h"
 
+using namespace std;
+
 Colourscale :: Colourscale( int ts, CScale_t tcs )
 {
 	n = 0;
