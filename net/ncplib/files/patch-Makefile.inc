--- Makefile.inc.orig	Fri Apr 25 20:10:52 2003
+++ Makefile.inc	Fri Apr 25 20:14:54 2003
@@ -11,6 +11,7 @@
 BINDIR?=${PREFIX}/bin
 NCPSBINDIR=${PREFIX}/sbin
 MANDIR=${PREFIX}/man/man
+NOOBJ=	yes
 
 CFLAGS	+= -Wall
 
@@ -18,9 +19,7 @@
 CFLAGS+=	-ggdb
 .endif
 
-.include <bsd.libnames.mk>
-
-.if !defined(LIBNCP) ||  defined(COMPLETEBUILD)
+.if defined(COMPLETEBUILD)
 CFLAGS	+= -L../lib/ncp
 CFLAGS	+= -I../include
 LIBNCP	= ../lib/ncp/libncp.a
