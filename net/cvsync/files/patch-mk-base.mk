--- mk/base.mk.orig	2005-01-24 16:45:13.000000000 +0900
+++ mk/base.mk	2013-10-07 04:38:38.000000000 +0900
@@ -91,8 +91,8 @@
 endif # SunOS
 
 PREFIX ?= /usr/local
-BINDIR ?= ${PREFIX}/bin
-MANDIR ?= ${PREFIX}/man
+BINDIR ?= ${DESTDIR}${PREFIX}/bin
+MANDIR ?= ${DESTDIR}${PREFIX}/man
 
 BINOWN ?= root
 BINGRP ?= wheel
