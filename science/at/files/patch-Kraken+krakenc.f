--- Kraken/krakenc.f~	Thu May 14 08:46:37 1998
+++ Kraken/krakenc.f	Fri Jan 12 17:39:37 2007
@@ -404,8 +404,8 @@
 
          IF ( SQRT( OMEGA2 ) / REAL( SQRT( X ) ) .GT. CHIGH ) THEN
 C           --- Mode outside, restart at a random point
-            CTRY = CLOW     + RAN( ISEED ) * ( CHIGH - CLOW )
-     &      + ( 0.0, 0.01 ) * RAN( ISEED ) * CLOW
+            CTRY = CLOW     + RAN( ISEED(1) ) * ( CHIGH - CLOW )
+     &      + ( 0.0, 0.01 ) * RAN( ISEED(1) ) * CLOW
          
             X = ( 1.0, 0.0 ) * OMEGA2 / CTRY ** 2
 
