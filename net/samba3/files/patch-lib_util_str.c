--- lib/util_str.c.orig	Tue Apr 20 22:42:55 2004
+++ lib/util_str.c	Fri May 14 02:02:30 2004
@@ -1980,10 +1980,16 @@
 {
 	int bits = 0;
 	int char_count = 0;
-	size_t out_cnt = 0;
-	size_t len = data.length;
-	size_t output_len = data.length * 2;
-	char *result = malloc(output_len); /* get us plenty of space */
+	size_t out_cnt, len, output_len;
+	char *result;
+
+        if (!data.length || !data.data)
+		return NULL;
+
+	out_cnt = 0;
+	len = data.length;
+	output_len = data.length * 2;
+	result = malloc(output_len); /* get us plenty of space */
 
 	while (len-- && out_cnt < (data.length * 2) - 5) {
 		int c = (unsigned char) *(data.data++);
