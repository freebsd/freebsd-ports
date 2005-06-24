--- agent/command-ssh.c.orig	Fri Jun 24 17:04:13 2005
+++ agent/command-ssh.c	Fri Jun 24 17:04:23 2005
@@ -1988,7 +1988,7 @@
   gcry_sexp_t valuelist = NULL;
   gcry_sexp_t sublist = NULL;
   gcry_mpi_t sig_value = NULL;
-  unsigned char *sig_blob = NULL;;
+  unsigned char *sig_blob = NULL;
   size_t sig_blob_n = 0;
   char *identifier = NULL;
   const char *identifier_raw;
