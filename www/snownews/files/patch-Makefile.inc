--- Makefile.inc.orig	Fri Jan 23 20:13:29 2004
+++ Makefile.inc	Tue Jan 27 15:46:37 2004
@@ -1,5 +1,5 @@
 CC = gcc
-MAKE = make
+MAKE = gmake
 INSTALL = install
 PREFIX = /usr/local
 LOCALEPATH = $(PREFIX)/share/locale
@@ -8,3 +8,4 @@
 	doc po \
 	main.c interface.c netio.c xmlparse.c updatecheck.c os-support.c conversions.c dialog.c ui-support.c categories.c about.c cookies.c \
 	config.h version.h main.h interface.h netio.h xmlparse.h updatecheck.h os-support.h conversions.h dialog.h ui-support.h categories.h about.h cookies.h
+EXTRA_LDFLAGS = -lintl -liconv
