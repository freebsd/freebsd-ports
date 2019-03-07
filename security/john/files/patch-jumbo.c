--- jumbo.c.orig	2014-12-18 07:59:02 UTC
+++ jumbo.c
@@ -334,3 +334,23 @@ int setenv(const char *name, const char *val, int over
 	return 0;
 }
 #endif
+
+int check_pkcs_pad(const unsigned char* data, size_t len, int blocksize)
+{
+	int pad_len = data[len - 1];
+	int padding = pad_len;
+	int real_len = len - pad_len;
+	const unsigned char *p = data + real_len;
+
+	if (pad_len > blocksize || pad_len < 1)
+		return -1;
+
+	if (len < blocksize)
+		return -1;
+
+	while (pad_len--)
+		if (*p++ != padding)
+			return -1;
+
+	return real_len;
+}
