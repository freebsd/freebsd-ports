--- compat/sha1.h.orig	Thu Apr 14 16:07:26 2005
+++ compat/sha1.h	Thu Apr 14 12:52:54 2005
@@ -18,21 +18,13 @@
 #include <sys/cdefs.h>
 
 __BEGIN_DECLS
-void SHA1Transform(u_int32_t [5], const unsigned char [64])
-		__attribute__((__bounded__(__minbytes__,1,5)))
-		__attribute__((__bounded__(__minbytes__,2,64)));
+void SHA1Transform(u_int32_t [5], const unsigned char [64]);
 void SHA1Init(SHA1_CTX *);
-void SHA1Update(SHA1_CTX *, const unsigned char *, unsigned int)
-		__attribute__((__bounded__(__string__,2,3)));
-void SHA1Final(unsigned char [20], SHA1_CTX *)
-		__attribute__((__bounded__(__minbytes__,1,20)));
-char *SHA1End(SHA1_CTX *, char *)
-		__attribute__((__bounded__(__minbytes__,2,41)));
-char *SHA1File(char *, char *)
-		__attribute__((__bounded__(__minbytes__,2,41)));
-char *SHA1Data(const unsigned char *, size_t, char *)
-		__attribute__((__bounded__(__string__,1,2)))
-		__attribute__((__bounded__(__minbytes__,3,41)));
+void SHA1Update(SHA1_CTX *, const unsigned char *, unsigned int);
+void SHA1Final(unsigned char [20], SHA1_CTX *);
+char *SHA1End(SHA1_CTX *, char *);
+char *SHA1File(char *, char *);
+char *SHA1Data(const unsigned char *, size_t, char *);
 __END_DECLS
 
 #define SHA1_DIGESTSIZE       20
