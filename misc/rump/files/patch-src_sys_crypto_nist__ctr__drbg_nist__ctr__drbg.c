--- src/sys/crypto/nist_ctr_drbg/nist_ctr_drbg.c.orig	2016-08-02 11:51:10 UTC
+++ src/sys/crypto/nist_ctr_drbg/nist_ctr_drbg.c
@@ -153,7 +153,7 @@ typedef struct {
 static inline int
 check_int_alignment(const void *p)
 {
-	intptr_t ip = (const char *)p - (const char *)0;
+	intptr_t ip = (intptr_t)p;
 
 	if (ip & (sizeof(int) - 1))
 		return 0;
