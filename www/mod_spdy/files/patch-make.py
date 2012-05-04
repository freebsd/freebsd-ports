--- tools/gyp/pylib/gyp/generator/make.py.org	2012-03-31 16:29:12.063738000 +0900
+++ tools/gyp/pylib/gyp/generator/make.py	2012-03-31 16:59:21.541770196 +0900
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
