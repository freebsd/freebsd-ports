--- Makefile.inc.orig	Sun Mar  7 22:41:07 2004
+++ Makefile.inc	Sat Apr  3 09:05:38 2004
@@ -1,10 +1,11 @@
-CC = gcc
-MAKE = make
+CC ?= gcc
+MAKE = gmake
 INSTALL = install
-PREFIX = /usr/local
+#PREFIX = /usr/local
 LOCALEPATH = $(PREFIX)/share/locale
 DISTFILES = AUTHOR COPYING CREDITS Changelog README README.de README.colors README.patching INSTALL INSTALL.solaris INSTALL.FreeOpenNetBSD opml2snow \
 	Makefile Makefile.inc Makefile.solaris \
 	doc po scripts \
 	main.c interface.c netio.c xmlparse.c updatecheck.c os-support.c conversions.c dialog.c ui-support.c categories.c about.c cookies.c setup.c net-support.c digcalc.c md5.c filters.c \
 	config.h version.h main.h interface.h netio.h xmlparse.h updatecheck.h os-support.h conversions.h dialog.h ui-support.h categories.h about.h cookies.h setup.h net-support.h digcalc.h md5.h filters.h
+EXTRA_LDFLAGS = -lintl -liconv
