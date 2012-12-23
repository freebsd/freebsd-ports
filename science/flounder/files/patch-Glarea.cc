--- src/Glarea.cc.orig	2002-12-20 03:56:35.000000000 +0900
+++ src/Glarea.cc	2012-12-12 23:16:47.000000000 +0900
@@ -918,7 +918,7 @@
 			igbname = fname + ".gz";
 			if( (in=gzopen( igbname.c_str(), "r" )) == NULL ) {
 				igbname = fname + ".igb.gz"; 
-				if( (in=fopen( igbname.c_str(), "rb" )) == NULL ) 
+				if( (in=(gzFile)fopen( igbname.c_str(), "rb" )) == NULL ) 
 					return 1;
 			}
 		}
