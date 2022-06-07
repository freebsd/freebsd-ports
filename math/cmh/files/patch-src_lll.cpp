- reported to Emmanuel Thomé <emmanuel.thome@inria.fr> on 06/06/2022

--- src/lll.cpp.orig	2021-02-05 17:21:58 UTC
+++ src/lll.cpp
@@ -37,7 +37,7 @@
 #ifdef HAVE_FPLLL
 static void lll_fplll (mpz_t *v, mpz_t **M, const int m, const int n)
 {
-   ZZ_mat <mpz_t> Mp (m, n);
+   fplll::ZZ_mat <mpz_t> Mp (m, n);
    int i, j;
 
    for (i = 0; i < m; i++)
