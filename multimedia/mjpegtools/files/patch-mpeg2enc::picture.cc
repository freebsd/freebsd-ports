--- mpeg2enc/picture.cc.orig	Thu Jul 22 18:23:54 2004
+++ mpeg2enc/picture.cc	Thu Jul 22 18:24:32 2004
@@ -83,9 +83,9 @@
     }
 
 
-	curref = new (uint8_t *)[5];
-	curorg = new (uint8_t *)[5];
-	pred   = new (uint8_t *)[5];
+	curref = new uint8_t * [5];
+	curorg = new uint8_t * [5];
+	pred   = new uint8_t * [5];
 
 	for( i = 0 ; i<3; i++)
 	{
