--- tools/gyp/pylib/gyp/generator/make.py.orig	2011-10-07 11:51:41.000000000 +0300
+++ tools/gyp/pylib/gyp/generator/make.py	2011-10-08 22:49:05.683824673 +0300
@@ -249,13 +249,13 @@
 # in gyp's make.py where ARFLAGS.host etc. is computed.
 # TODO(evan): move all cross-compilation logic to gyp-time so we don't need
 # to replicate this environment fallback in make as well.
-CC.host ?= gcc
-CFLAGS.host ?=
-CXX.host ?= g++
-CXXFLAGS.host ?=
-LINK.host ?= g++
-LDFLAGS.host ?=
-AR.host ?= ar
+CC.host ?= $(CC)
+CFLAGS.host ?= $(CFLAGS)
+CXX.host ?= $(CXX) 
+CXXFLAGS.host ?= $(CXXFLAGS)
+LINK.host ?= $(LINK)
+LDFLAGS.host ?= $(LDFLAGS)
+AR.host ?= $(AR)
 ARFLAGS.host := %(ARFLAGS.host)s
 
 # Define a dir function that can handle spaces.
