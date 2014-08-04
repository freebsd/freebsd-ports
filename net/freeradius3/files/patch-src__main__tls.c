--- ./src/main/tls.c.orig	2014-08-04 08:03:48.000000000 -0400
+++ ./src/main/tls.c	2014-08-04 08:04:14.000000000 -0400
@@ -63,8 +63,8 @@
 static libssl_defect_t libssl_defects[] =
 {
 	{
-		.low		= 0x010001000,		/* 1.0.1  */
-		.high		= 0x01000106f,		/* 1.0.1f */
+		.low		= 0x090001000,		/* 9.0.1  */
+		.high		= 0x09000106f,		/* 9.0.1f */
 		.id		= "CVE-2014-0160",
 		.name		= "Heartbleed",
 		.comment	= "For more information see http://heartbleed.com"
