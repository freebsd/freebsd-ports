--- test/testdev.c.orig	Fri Jul 18 12:08:02 2003
+++ test/testdev.c	Fri Jul 18 12:08:22 2003
@@ -849,8 +849,7 @@
 		return( status );
   #else
 	puts( "Skipping CAW functionality test (uncomment the "
-		  "TEST_CAW_FUNCTIONALITY #define\n  in " __FILE__ " to enable
-		  this)." );
+		  "TEST_CAW_FUNCTIONALITY #define\n  in " __FILE__ " to enable this)." );
   #endif /* TEST_CAW_FUNCTIONALITY */
 	status = testCryptoDevice( CRYPT_DEVICE_FORTEZZA, "Fortezza card",
 							   &fortezzaDeviceInfo );
