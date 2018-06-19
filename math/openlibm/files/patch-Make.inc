--- Make.inc.orig	2018-06-18 21:22:47 UTC
+++ Make.inc
@@ -10,7 +10,7 @@ VERSION = 0.6.0
 SOMAJOR = 2
 SOMINOR = 5
 DESTDIR =
-prefix = /usr/local
+prefix ?= /usr/local
 bindir = $(prefix)/bin
 libdir = $(prefix)/lib
 includedir = $(prefix)/include
