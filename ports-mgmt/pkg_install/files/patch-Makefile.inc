--- Makefile.inc.orig	Tue Dec 21 05:16:03 2004
+++ Makefile.inc	Sat Feb 26 17:02:17 2005
@@ -7,9 +7,11 @@
 .endif
 
 .if !defined(NO_CRYPT) && !defined(NO_OPENSSL) && \
-    defined(LDADD) && ${LDADD:M-lfetch} != ""
+	defined(LDADD)
+.if  ${LDADD:M-lfetch} != ""
 DPADD+=		${LIBSSL} ${LIBCRYPTO}
 LDADD+=		-lssl -lcrypto
+.endif
 .endif
 
 # Inherit BINDIR from one level up.
