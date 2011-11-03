--- tools/gyp/pylib/gyp/generator/make.py.orig	Mon Oct 31 10:37:12 2011
+++ tools/gyp/pylib/gyp/generator/make.py	Mon Oct 31 10:39:06 2011
@@ -129,11 +129,11 @@
 # in gyp's make.py where ARFLAGS.host etc. is computed.
 # TODO(evan): move all cross-compilation logic to gyp-time so we don't need
 # to replicate this environment fallback in make as well.
-CC.host ?= gcc
+CC.host ?= cc
 CFLAGS.host ?=
-CXX.host ?= g++
+CXX.host ?= c++
 CXXFLAGS.host ?=
-LINK.host ?= g++
+LINK.host ?= c++
 LDFLAGS.host ?=
 AR.host ?= ar
 ARFLAGS.host := %(ARFLAGS.host)s
