--- common.mak.orig	2018-02-24 09:43:21 UTC
+++ common.mak
@@ -4,7 +4,7 @@ CFLAGS ?= -Wall -g -O2
 PREFIX ?= /usr/local
 
 bindir ?= $(PREFIX)/bin
-mandir ?= $(PREFIX)/share/man
+mandir ?= $(PREFIX)/share/man
 libdir ?= $(PREFIX)/lib
 docdir ?= $(PREFIX)/share/doc
 includedir ?=  $(PREFIX)/include
