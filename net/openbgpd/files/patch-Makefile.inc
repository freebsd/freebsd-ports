Index: Makefile.inc
===================================================================
RCS file: Makefile.inc
diff -N Makefile.inc
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ Makefile.inc	30 Jun 2009 07:19:13 -0000	1.2
@@ -0,0 +1,5 @@
+# $hrs: openbgpd/Makefile.inc,v 1.2 2009/06/30 07:19:13 hrs Exp $
+
+PREFIX?=	/usr/local
+BINDIR?=	${PREFIX}/sbin
+MANDIR?=	${PREFIX}/man/man
