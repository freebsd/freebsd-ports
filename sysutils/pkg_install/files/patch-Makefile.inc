--- Makefile.inc.orig	Mon Oct 18 15:09:20 2004
+++ Makefile.inc	Mon Oct 18 15:10:08 2004
@@ -7,10 +7,12 @@
 .endif
 
 .if !defined(NOCRYPT) && !defined(NO_OPENSSL) && \
-    defined(LDADD) && ${LDADD:M-lfetch} != ""
+    defined(LDADD)
+.if  ${LDADD:M-lfetch} != ""
 DISTRIBUTION=	crypto
 DPADD+=		${LIBSSL} ${LIBCRYPTO}
 LDADD+=		-lssl -lcrypto
+.endif
 .endif
 
 # Inherit BINDIR from one level up.
