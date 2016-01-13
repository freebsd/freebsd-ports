--- sysutils/ansible1/Makefile
+++ sysutils/ansible1/Makefile
@@ -0,0 +1,14 @@
+# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
+# $FreeBSD$
+
+PKGNAMESUFFIX=	1
+PORTVERSION=	1.9.4
+
+CONFLICTS=	ansible-*
+
+MASTERDIR=	${.CURDIR}/../ansible
+DISTINFO_FILE=	${.CURDIR}/distinfo
+
+SHEBANG_FILES=	lib/ansible/runner/action_plugins/synchronize.py
+
+.include "${MASTERDIR}/Makefile"
