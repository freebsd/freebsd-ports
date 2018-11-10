--- common.mk.orig	2018-08-28 18:46:05 UTC
+++ common.mk
@@ -3,7 +3,7 @@
 LDFLAGS = -X cypherpunks.ru/govpn.Version=$(VERSION)
 PREFIX ?= /usr/local
 BINDIR = $(DESTDIR)$(PREFIX)/bin
-INFODIR = $(DESTDIR)$(PREFIX)/info
+INFODIR = $(DESTDIR)$(PREFIX)/share/info
 SHAREDIR = $(DESTDIR)$(PREFIX)/share/govpn
 DOCDIR = $(DESTDIR)$(PREFIX)/share/doc/govpn
 
