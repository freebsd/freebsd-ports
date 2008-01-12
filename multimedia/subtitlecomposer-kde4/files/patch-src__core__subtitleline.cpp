--- ./src/core/subtitleline.cpp.orig	2008-01-08 09:16:27.000000000 +0300
+++ ./src/core/subtitleline.cpp	2008-01-08 15:54:39.000000000 +0300
@@ -41,7 +41,7 @@
 	if ( flag < 1 )
 		return ErrorUNKNOWN;
 
-	int id = (int)log2( flag );
+	int id = int( log( flag ) * M_LN2 );
 	return id < ErrorSIZE ? (ErrorID)id : ErrorUNKNOWN;
 }
 
