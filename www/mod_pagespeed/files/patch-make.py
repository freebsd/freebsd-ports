--- tools/gyp/pylib/gyp/generator/make.py.orig	2012-07-12 00:18:25.000000000 +0000
+++ tools/gyp/pylib/gyp/generator/make.py	2012-07-15 14:59:48.000000000 +0000
@@ -269,12 +269,12 @@
 # in gyp's make.py where ARFLAGS.host etc. is computed.
 # TODO(evan): move all cross-compilation logic to gyp-time so we don't need
 # to replicate this environment fallback in make as well.
-CC.host ?= gcc
+CC.host ?= %%CC%%
 CFLAGS.host ?=
-CXX.host ?= g++
+CXX.host ?= %%CXX%%
 CXXFLAGS.host ?=
-LINK.host ?= g++
-LDFLAGS.host ?=
+LINK.host ?= %%CXX%%
+LDFLAGS.host ?= -Wl,-rpath,%%LOCALBASE%%/lib/%%CC%%
 AR.host ?= ar
 ARFLAGS.host := %(ARFLAGS.host)s
 
