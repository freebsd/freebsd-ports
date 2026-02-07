--- a/lib/sysxattrs.c.orig	2022-01-16 01:21:01.000000000 +0000
+++ b/lib/sysxattrs.c	2025-07-28 12:05:43.501532000 +0000
@@ -126,22 +126,29 @@
 	unsigned char keylen;
 	ssize_t off, len = extattr_list_link(path, EXTATTR_NAMESPACE_USER, list, size);
 
-	if (len <= 0 || (size_t)len > size)
+	if (len <= 0 || size == 0)
 		return len;
 
+	if ((size_t)len == size) {
+		/* extattr_list_link fills a buffer with a list of file attributes.
+		 * If the buffer size is too small the content is truncated and
+		 * extattr_list_link returns the number of written bytes and no
+		 * error is raised. If size == len assumes the buffer was too small
+		 * and behave like Linux requesting a larger buffer. */
+		errno = ERANGE;
+		return -1;
+	}
+
 	/* FreeBSD puts a single-byte length before each string, with no '\0'
 	 * terminator.  We need to change this into a series of null-terminted
 	 * strings.  Since the size is the same, we can simply transform the
 	 * output in place. */
-	for (off = 0; off < len; off += keylen + 1) {
-		keylen = ((unsigned char*)list)[off];
-		if (off + keylen >= len) {
-			/* Should be impossible, but kernel bugs happen! */
-			errno = EINVAL;
-			return -1;
-		}
-		memmove(list+off, list+off+1, keylen);
-		list[off+keylen] = '\0';
+	keylen = (unsigned char)list[0];
+	memmove(list, list+1, len-1);
+	list[len-1] = '\0';
+	for (off = keylen; off < (len - 1); off += (keylen + 1)) {
+		keylen = (unsigned char)list[off];
+		list[off] = '\0';
 	}
 
 	return len;
