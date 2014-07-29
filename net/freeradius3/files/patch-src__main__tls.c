--- ./src/main/tls.c.orig	2014-07-29 15:55:29.000000000 -0400
+++ ./src/main/tls.c	2014-07-29 15:57:18.000000000 -0400
@@ -62,13 +62,6 @@
 /* Record critical defects in libssl here (newest first)*/
 static libssl_defect_t libssl_defects[] =
 {
-	{
-		.low		= 0x010001000,		/* 1.0.1  */
-		.high		= 0x01000106f,		/* 1.0.1f */
-		.id		= "CVE-2014-0160",
-		.name		= "Heartbleed",
-		.comment	= "For more information see http://heartbleed.com"
-	}
 };
 
 /* record */
