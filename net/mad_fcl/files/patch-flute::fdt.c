--- flute/fdt.c.orig	Fri Feb 13 15:58:54 2004
+++ flute/fdt.c	Fri Feb 13 15:58:54 2004
@@ -113,14 +113,14 @@
 #ifdef WIN32
                                 file->file_len = _atoi64(*(++atts));
 #else
-                                file->file_len = atoll(*(++atts));
+                                file->file_len = strtoll(*(++atts), NULL, 10);
 #endif
                         }
 			else if(!strcmp(*atts, "Transfer-Length")) {
 #ifdef WIN32			  
 				file->toi_len = _atoi64(*(++atts));
 #else
-				file->toi_len = atoll(*(++atts));
+				file->toi_len = strtoll(*(++atts),NULL, 10);
 #endif 
 			}
 			else if(!strcmp(*atts, "Content-Type")) {
@@ -179,7 +179,7 @@
 #ifdef WIN32
 				fdt->expires = _atoi64(*(++atts));
 #else
-				fdt->expires = atoll(*(++atts));
+				fdt->expires = strtoll(*(++atts), NULL, 10);
 #endif
 			}
 			else if(!strcmp(*atts, "Complete")) {
