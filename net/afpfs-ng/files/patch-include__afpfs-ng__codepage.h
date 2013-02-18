--- include/afpfs-ng/codepage.h.orig	1970-01-01 00:00:00.000000000 +0000
+++ include/afpfs-ng/codepage.h	2012-10-14 13:11:33.000000000 +0000
@@ -0,0 +1,11 @@
+#ifndef __CODE_PAGE_H_
+#define __CODE_PAGE_H_
+int convert_utf8dec_to_utf8pre(const char *src, int src_len,
+	char * dest, int dest_len);
+int convert_utf8pre_to_utf8dec(const char * src, int src_len, 
+	char * dest, int dest_len);
+int convert_path_to_unix(char encoding, char * dest, 
+	char * src, int dest_len);
+int convert_path_to_afp(char encoding, char * dest, 
+	char * src, int dest_len);
+#endif
diff -Naur afpfs-ng-0.8.1.orig/include/afpfs-ng/dsi.h afpfs-ng-0.8.1/include/afpfs-ng/dsi.h
