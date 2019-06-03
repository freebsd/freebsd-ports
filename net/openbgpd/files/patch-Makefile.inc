Index: Makefile.inc
===================================================================
RCS file: Makefile.inc
diff -N Makefile.inc
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ Makefile.inc	16 May 2014 01:06:14 -0000	1.5
@@ -0,0 +1,5 @@
+# $hrs: openbgpd/Makefile.inc,v 1.5 2014/05/16 01:06:14 hrs Exp $
+
+PREFIX?=	/usr/local
+BINDIR?=	${PREFIX}/sbin
+MANDIR?=	${PREFIX}/man/man
