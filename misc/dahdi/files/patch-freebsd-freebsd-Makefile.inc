--- freebsd/freebsd/Makefile.inc.orig	2010-09-01 13:50:13.000000000 +0700
+++ freebsd/freebsd/Makefile.inc	2010-09-01 13:50:34.000000000 +0700
@@ -8,7 +8,11 @@
 #CFLAGS+=	-DINVARIANT_SUPPORT -DINVARIANTS -DDIAGNOSTIC
 
 CP?=		cp
+.if defined(NO_FETCH)
+FETCH?=		@echo Skipping fetch
+.else
 FETCH?=		fetch
+.endif
 MKDIR?=		mkdir -p
 INSTALL_DATA?=	${INSTALL} -m ${SHAREMODE} -o ${SHAREOWN} -g ${SHAREGRP} -c
 TAR?=		tar
