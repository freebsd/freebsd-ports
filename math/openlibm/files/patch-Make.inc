--- Make.inc.orig	2014-12-01 13:10:35 UTC
+++ Make.inc
@@ -7,11 +7,17 @@ VERSION = 0.4
 SOMAJOR = 1
 SOMINOR = 0
 DESTDIR =
-prefix = /usr/local
+prefix ?= /usr/local
 bindir = $(prefix)/bin
 libdir = $(prefix)/lib
 includedir = $(prefix)/include
 
+pkgconfigdir = $(libdir)/pkgconfig
+
+ifeq ($(OS), FreeBSD)
+pkgconfigdir = $(prefix)/libdata/pkgconfig
+endif
+
 USEGCC = 1
 USECLANG = 0
 
@@ -20,6 +26,11 @@ USEGCC = 0
 USECLANG = 1
 endif
 
+ifeq ($(OS), FreeBSD)
+USEGCC = 0
+USECLANG = 1
+endif
+
 AR = ar
 
 ifeq ($(USECLANG),1)
@@ -90,6 +101,7 @@ ifeq ($(OS), FreeBSD)
 SHLIB_EXT = so
 SONAME_FLAG = -soname
 CFLAGS_add+=-fPIC
+libdatadir = $(prefix)/libdata
 endif
 
 ifeq ($(OS), Darwin)
