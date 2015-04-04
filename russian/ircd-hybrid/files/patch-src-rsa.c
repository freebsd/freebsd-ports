--- src/rsa.c.orig	2006-12-19 16:53:04.000000000 +0100
+++ src/rsa.c	2015-03-21 14:49:27.236087141 +0100
@@ -186,6 +186,7 @@
 int
 get_randomness(unsigned char *buf, int length)
 {
+#ifdef HAVE_RAND_EGD
     /* Seed OpenSSL PRNG with EGD enthropy pool -kre */
     if (ConfigFileEntry.use_egd &&
         (ConfigFileEntry.egdpool_path != NULL))
@@ -193,6 +194,7 @@
       if (RAND_egd(ConfigFileEntry.egdpool_path) == -1)
             return -1;
     }
+#endif
 
   if (RAND_status())
     return (RAND_bytes(buf, length));
