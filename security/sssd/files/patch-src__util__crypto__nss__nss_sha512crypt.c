--- src/util/crypto/nss/nss_sha512crypt.c.orig	2020-03-17 13:31:28 UTC
+++ src/util/crypto/nss/nss_sha512crypt.c
@@ -29,6 +29,14 @@
 #include <sechash.h>
 #include <pk11func.h>
 
+#ifndef HAVE_MEMPCPY
+static void *
+mempcpy (void *dest, const void *src, size_t n)
+{
+  return (char *) memcpy (dest, src, n) + n;
+}
+#endif /* HAVE_MEMPCPY */
+
 /* Define our magic string to mark salt for SHA512 "encryption" replacement. */
 const char sha512_salt_prefix[] = "$6$";
 #define SALT_PREF_SIZE (sizeof(sha512_salt_prefix) - 1)
