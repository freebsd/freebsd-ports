--- g10/pkglue.c.orig	2011-01-09 14:06:16.000000000 -0800
+++ g10/pkglue.c	2011-07-12 21:32:41.000000000 -0700
@@ -34,10 +34,10 @@
 {
   gcry_sexp_t list;
   gcry_mpi_t data;
-  
+
   list = gcry_sexp_find_token (sexp, item, 0);
   assert (list);
-  data = gcry_sexp_nth_mpi (list, 1, 0);
+  data = gcry_sexp_nth_mpi (list, 1, GCRYMPI_FMT_USG);
   assert (data);
   gcry_sexp_release (list);
   return data;
@@ -293,7 +293,7 @@
   if (rc)
     return rc;
 
-  *result = gcry_sexp_nth_mpi (s_plain, 0, 0);
+  *result = gcry_sexp_nth_mpi (s_plain, 0, GCRYMPI_FMT_USG);
   gcry_sexp_release (s_plain);
   if (!*result)
     return -1;			/* oops */
