--- Makefile.inc.orig	Wed Mar  6 01:23:27 2002
+++ Makefile.inc	Mon Jun 24 20:28:00 2002
@@ -17,10 +17,19 @@
 
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
+.if (${SKEY} == "yes")
+LDADD+=		-lopie
+.endif
 .endif
