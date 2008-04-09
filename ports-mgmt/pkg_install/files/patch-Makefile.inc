--- Makefile.inc.orig	2008-04-09 16:15:05.000000000 +0100
+++ Makefile.inc	2008-04-09 16:15:21.000000000 +0100
@@ -4,11 +4,13 @@
 
 LIBINSTALL=	${.OBJDIR}/../lib/libinstall.a
 
-.if ${MK_OPENSSL} != "no" && \
-    defined(LDADD) && ${LDADD:M-lfetch} != ""
+.if !defined(NO_CRYPT) && !defined(NO_OPENSSL) && \
+	defined(LDADD)
+.if  ${LDADD:M-lfetch} != ""
 DPADD+=		${LIBSSL} ${LIBCRYPTO}
 LDADD+=		-lssl -lcrypto
 .endif
+.endif
 
 # Inherit BINDIR from one level up.
 .include "../Makefile.inc"
