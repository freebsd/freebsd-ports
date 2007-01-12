--- Kraken/covar.f~	Thu Feb 26 14:42:17 1998
+++ Kraken/covar.f	Fri Jan 12 17:40:53 2007
@@ -252,8 +252,8 @@
       COMPLEX   NOISE( * )
 
       DO IRD = 1, NRD
-         X = RAN( ISEED ) + 0.000001
-         Y = RAN( ISEED )
+         X = RAN( ISEED(1) ) + 0.000001
+         Y = RAN( ISEED(1) )
 
          NOISE( IRD ) = SIGMA *
      &      SQRT( -LOG( X ) ) * EXP( CI * 2.0 * PI * Y )
@@ -287,8 +287,8 @@
       DO MODE = 1, M
 
 C        --- compute the random coefficient
-         X = RAN( ISEED ) + 0.000001
-         Y = RAN( ISEED )
+         X = RAN( ISEED(1) ) + 0.000001
+         Y = RAN( ISEED(1) )
          COEF = SQRT( -LOG( X ) ) * EXP( CI * 2.0 * PI * Y )
 
 C        --- loop over receivers
