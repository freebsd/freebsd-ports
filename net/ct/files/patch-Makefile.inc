--- Makefile.inc.orig	2013-06-17 01:17:58.000000000 +0900
+++ Makefile.inc	2013-06-17 01:18:14.000000000 +0900
@@ -1,4 +1,4 @@
-PREFIX=/usr/local/v6eval
+PREFIX?=	%%PREFIX%%/v6eval
 
 .ifndef AUTORUN
 AUTORUN = $(PREFIX)/bin/autorun
