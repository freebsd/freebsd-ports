--- Makefile.inc.orig	Sun Jul 29 16:00:07 2001
+++ Makefile.inc	Wed Oct  3 13:49:31 2001
@@ -17,10 +17,16 @@
 
 .include <bsd.obj.mk>
 
-.if exists(${.CURDIR}/../lib/${__objdir})
-LDADD+=         -L${.CURDIR}/../lib/${__objdir} -lssh
-DPADD+=         ${.CURDIR}/../lib/${__objdir}/libssh.a
-.else
+AFS?=		no
+KERBEROS?=	no
+KERBEROS5?=	no
+PAM?=		no
+SKEY?=		no
+TCP_WRAPPERS?=	yes
+
+CFLAGS+=	-I${OPENSSLINC} ${INET6FLAGS}
+
+.if !defined(IGNORE_LIBSSH)
 LDADD+=         -L${.CURDIR}/../lib -lssh
 DPADD+=         ${.CURDIR}/../lib/libssh.a
 .endif
