--- Make.inc.orig	2016-05-23 11:57:41 UTC
+++ Make.inc
@@ -3,11 +3,11 @@
 OS := $(shell uname)
 # Do not forget to bump SOMINOR when changing VERSION,
 # and SOMAJOR when breaking ABI in a backward-incompatible way
-VERSION = 0.5.1-dev
+VERSION = 0.5.1
 SOMAJOR = 2
 SOMINOR = 2
 DESTDIR =
-prefix = /usr/local
+prefix ?= /usr/local
 bindir = $(prefix)/bin
 libdir = $(prefix)/lib
 includedir = $(prefix)/include
