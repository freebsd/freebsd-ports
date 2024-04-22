--- Makefile.inc.orig	2024-03-28 15:31:27 UTC
+++ Makefile.inc
@@ -4,5 +4,5 @@ SHAREDIR?=	${PREFIX}/share
 ETCDIR?=	${PREFIX}/etc
 .if defined(PREFIX)
 SHAREDIR?=	${PREFIX}/share
-MANDIR?=	${PREFIX}/man/man
+MANDIR?=	${PREFIX}/share/man/man
 .endif
