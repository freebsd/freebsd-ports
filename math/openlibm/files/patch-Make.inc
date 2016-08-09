--- Make.inc.orig	2016-08-06 15:00:31 UTC
+++ Make.inc
@@ -7,7 +7,7 @@ VERSION = 0.5.2
 SOMAJOR = 2
 SOMINOR = 3
 DESTDIR =
-prefix = /usr/local
+prefix ?= /usr/local
 bindir = $(prefix)/bin
 libdir = $(prefix)/lib
 includedir = $(prefix)/include
