--- Makefile.inc.orig	Wed Mar  6 01:23:27 2002
+++ Makefile.inc	Wed Jul 24 05:42:52 2002
@@ -15,12 +15,16 @@
 #CFLAGS+=	-DSMARTCARD
 #LDADD+=	-lsectok
 
-.include <bsd.obj.mk>
+AFS?=		no
+KERBEROS?=	no
+KERBEROS5?=	no
+PAM?=		no
+SKEY?=		no
+TCP_WRAPPERS?=	yes
 
-.if exists(${.CURDIR}/../lib/${__objdir})
-LDADD+=         -L${.CURDIR}/../lib/${__objdir} -lssh
-DPADD+=         ${.CURDIR}/../lib/${__objdir}/libssh.a
-.else
+CFLAGS+=	-I${OPENSSLINC} ${INET6FLAGS}
+
+.if !defined(IGNORE_LIBSSH)
 LDADD+=         -L${.CURDIR}/../lib -lssh
 DPADD+=         ${.CURDIR}/../lib/libssh.a
 .endif
