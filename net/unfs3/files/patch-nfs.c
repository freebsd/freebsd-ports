--- nfs.c.orig	Sat Dec  4 12:17:53 2004
+++ nfs.c	Sat Dec  4 12:18:20 2004
@@ -45,9 +45,10 @@
  * otherwise zero result structure and return with error status
  */
 #define PREP(p,f) do {						\
+                      unfs3_fh_t *fh;                           \
                       setegid(0);                               \
                       seteuid(0);                               \
-                      unfs3_fh_t *fh = (void *)f.data.data_val; \
+                      fh = (void *)f.data.data_val;             \
                       p = fh_decomp(f);				\
                       if (exports_options(p, rqstp, NULL, NULL) == -1) { \
                           memset(&result, 0, sizeof(result));	\
