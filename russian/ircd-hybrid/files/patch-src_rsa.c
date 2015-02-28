--- src/rsa.c.orig	2015-02-27 21:44:09.412197000 +0100
+++ src/rsa.c	2015-02-27 21:45:15.462084722 +0100
@@ -186,14 +186,6 @@
 int
 get_randomness(unsigned char *buf, int length)
 {
-    /* Seed OpenSSL PRNG with EGD enthropy pool -kre */
-    if (ConfigFileEntry.use_egd &&
-        (ConfigFileEntry.egdpool_path != NULL))
-    {
-      if (RAND_egd(ConfigFileEntry.egdpool_path) == -1)
-            return -1;
-    }
-
   if (RAND_status())
     return (RAND_bytes(buf, length));
   else /* XXX - abort? */
