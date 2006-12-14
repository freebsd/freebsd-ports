--- ed2k.c.orig	Sun Jun 13 19:47:20 2004
+++ ed2k.c	Thu Dec 14 10:40:21 2006
@@ -32,7 +32,7 @@
 #include <sys/stat.h>
 
 /* #define OFF_CONV "%ld"		/* off_t is long      (Linux)   */
-/* #define OFF_CONF "%lld"		/* off_t is long long (FreeBSD) */
+#define OFF_CONV "%lld"		/* off_t is long long (FreeBSD) */
 
 #ifndef OFF_CONV
 #  warning "You should define OFF_CONV (see the file)"
@@ -47,16 +47,27 @@
 
 typedef unsigned char md4_t[16];
 
+#if defined(WITH_RSA)
+
 typedef struct {
-    u_int32_t		state[4];
-    u_int32_t		count[2];
-    unsigned char	buffer[64];
+    u_int32_t         state[4];
+    u_int32_t         count[2];
+    unsigned char     buffer[64];
 } md4_ctx_t;
 
 void md4_init(md4_ctx_t *);
 void md4_update(md4_ctx_t *, unsigned char *, unsigned int);
 void md4_finish(md4_ctx_t *, md4_t);
 
+#else
+
+#include <md4.h>
+#define	md4_ctx_t	MD4_CTX
+#define	md4_init	MD4Init
+#define	md4_update	MD4Update
+#define	md4_finish(a,b)	MD4Final(b,a)
+
+#endif
 
 static char *progname;
 
@@ -86,16 +97,16 @@
 }
 
 
-static __inline__ char hdigit(q) {
+static __inline__ char hdigit(unsigned char q) {
     return ((q >= 10) ? 'W' : '0') + q;
 }
 
-char *digest_str(void *digest) {
+char *digest_str(unsigned char *digest) {
     static char internal_str[sizeof(md4_t)*2 + 1];
     char *str   = internal_str;
     int   dsize = sizeof(md4_t);
     while (dsize--) {
-	unsigned char d = *((unsigned char *)digest)++;
+	unsigned char d = *(digest++);
 	*(str++) = hdigit(d >> 4 );
 	*(str++) = hdigit(d & 0xf);
     }
@@ -181,6 +192,7 @@
 }
 
 
+#if defined(WITH_RSA)
 
 /*==> RSA Data Security, Inc. MD4 Message-Digest Algorithm =============*/
 
@@ -323,3 +335,5 @@
     md4_update (context, bits, 8);
     md4_encode (digest, context->state, 16);
 }
+
+#endif
