--- ssss.c.orig	Sun Sep  9 10:24:42 2007
+++ ssss.c	Sun Sep  9 10:24:48 2007
@@ -348,7 +348,7 @@
 #define MPZ_SWAP(A, B) \
   do { mpz_set(h, A); mpz_set(A, B); mpz_set(B, h); } while(0)
 
-int restore_secret(int n, mpz_t (*A)[n], mpz_t b[]) 
+int restore_secret(int n, void *A, mpz_t b[])
 {
   mpz_t (*AA)[n] = (mpz_t (*)[n])A;
   int i, j, k, found;
