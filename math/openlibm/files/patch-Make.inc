--- Make.inc.orig	2016-03-11 16:57:11 UTC
+++ Make.inc
@@ -3,11 +3,11 @@
 OS := $(shell uname)
 # Do not forget to bump SOMINOR when changing VERSION,
 # and SOMAJOR when breaking ABI in a backward-incompatible way
-VERSION = 0.5-dev
+VERSION = 0.5
 SOMAJOR = 2
 SOMINOR = 1
 DESTDIR =
-prefix = /usr/local
+prefix ?= /usr/local
 bindir = $(prefix)/bin
 libdir = $(prefix)/lib
 includedir = $(prefix)/include
