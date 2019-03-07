--- jumbo.h.orig	2014-12-18 07:59:02 UTC
+++ jumbo.h
@@ -388,4 +388,10 @@ extern int setenv(const char *name, const char *val, i
 //HAVE_STRTOL
 //HAVE_STRTOUL
 
+/*
+ * Standard PKCS padding check. On success, returns net length.
+ * On failure, returns -1.
+ */
+extern int check_pkcs_pad(const unsigned char* data, size_t len, int blocksize);
+
 #endif /* _JTR_JUMBO_H */
