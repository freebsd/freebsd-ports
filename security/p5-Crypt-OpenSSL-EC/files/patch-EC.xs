fix Unparseable XSUB parameter

--- EC.xs.orig	2025-07-13 08:50:06 UTC
+++ EC.xs
@@ -348,16 +348,6 @@ EC_POINT_make_affine(const EC_GROUP *group, EC_POINT *
 int 
 EC_POINT_make_affine(const EC_GROUP *group, EC_POINT *point, BN_CTX *ctx)
 
-#if 0
-
-int 
-EC_POINTs_make_affine(const EC_GROUP *group, size_t num, EC_POINT *p[], BN_CTX *ctx)
-
-int 
-EC_POINTs_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *n, size_t num, const EC_POINT *p[], const BIGNUM *m[], BN_CTX *ctx)
-
-#endif
-
 int 
 EC_POINT_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *n, const EC_POINT *q, const BIGNUM *m, BN_CTX *ctx)
 
