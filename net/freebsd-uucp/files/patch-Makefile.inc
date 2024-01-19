--- uucp/Makefile.inc.orig	2017-02-04 12:57:51 UTC
+++ uucp/Makefile.inc
@@ -23,7 +23,7 @@ uucpgroup=	uucp
 bindir=		${PREFIX}/bin
 sbindir=        ${PREFIX}/sbin
 libxdir=        ${PREFIX}/libexec/uucp
-MANDIR=		${PREFIX}/man/man
+MANDIR=		${PREFIX}/share/man/man
 INFODIR=	${PREFIX}/info
 
 # The directory to look in for new style configuration files (when
