--- flute/fdt.c.orig	Wed Mar  3 12:48:53 2004
+++ flute/fdt.c	Wed Mar  3 12:49:38 2004
@@ -114,7 +114,7 @@
 #ifdef WIN32     
 				file->file_len = _atoi64(*(++atts));
 #else               
-				file->file_len = atoll(*(++atts));				
+				file->file_len = strtoll(*(++atts), NULL, 10);				
 #endif
 				if(file->toi_len == 0) {
 					file->toi_len = file->file_len;
@@ -125,7 +125,7 @@
 #ifdef WIN32			  
 				file->toi_len = _atoi64(*(++atts));
 #else
-				file->toi_len = atoll(*(++atts));
+				file->toi_len = strtoll(*(++atts), NULL, 10);
 #endif 
 			}
 			else if(!strcmp(*atts, "Content-Type")) {
@@ -184,7 +184,7 @@
 #ifdef WIN32
 				fdt->expires = _atoi64(*(++atts));
 #else
-				fdt->expires = atoll(*(++atts));
+				fdt->expires = strtoll(*(++atts), NULL, 10);
 #endif
 			}
 			else if(!strcmp(*atts, "Complete")) {
