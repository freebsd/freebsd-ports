
$FreeBSD$

--- codecs/audio/ac3/coeff.c	2001/02/04 21:17:23	1.1
+++ codecs/audio/ac3/coeff.c	2001/02/04 21:17:55
@@ -254,7 +254,7 @@
 	11, 12, 14, 16
 };
 
-extern int error;
+extern int ac3_error;
 
 static void	coeff_reset(void);
 static float	coeff_get_float(uint16_t bap, uint16_t dithflag, uint16_t exp);
@@ -370,7 +370,7 @@
 
 error:
 	XMPS_DEBUG("** Invalid mantissa - skipping frame **");
-	error = 1;
+	ac3_error = 1;
 	
 	return 0.0;
 }
