--- lib/util_str.c.orig	Wed Dec 15 15:33:12 2004
+++ lib/util_str.c	Fri Dec 17 02:15:34 2004
@@ -2008,10 +2008,16 @@
 {
 	int bits = 0;
 	int char_count = 0;
-	size_t out_cnt = 0;
-	size_t len = data.length;
-	size_t output_len = data.length * 2;
-	char *result = SMB_MALLOC(output_len); /* get us plenty of space */
+	size_t out_cnt, len, output_len;
+	char *result;
+
+        if (!data.length || !data.data)
+		return NULL;
+
+	out_cnt = 0;
+	len = data.length;
+	output_len = data.length * 2;
+	result = SMB_MALLOC(output_len); /* get us plenty of space */
 
 	while (len-- && out_cnt < (data.length * 2) - 5) {
 		int c = (unsigned char) *(data.data++);
