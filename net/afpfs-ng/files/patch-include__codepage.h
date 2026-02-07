--- include/codepage.h.orig	2007-09-23 14:21:30.000000000 +0000
+++ include/codepage.h	2012-10-14 13:11:34.000000000 +0000
@@ -1,11 +0,0 @@
-#ifndef __CODE_PAGE_H_
-#define __CODE_PAGE_H_
-int convert_utf8dec_to_utf8pre(const char *src, int src_len,
-	char * dest, int dest_len);
-int convert_utf8pre_to_utf8dec(const char * src, int src_len, 
-	char * dest, int dest_len);
-int convert_path_to_unix(char encoding, char * dest, 
-	char * src, int dest_len);
-int convert_path_to_afp(char encoding, char * dest, 
-	char * src, int dest_len);
-#endif
diff -Naur afpfs-ng-0.8.1.orig/include/dsi.h afpfs-ng-0.8.1/include/dsi.h
