--- tools/gyp/pylib/gyp/generator/make.py.orig	2011-03-01 10:47:14.000000000 +0100
+++ tools/gyp/pylib/gyp/generator/make.py	2011-03-01 21:25:10.000000000 +0100
@@ -114,7 +114,7 @@
 #   export LINK="$(CXX)"
 #
 # This will allow make to invoke N linker processes as specified in -jN.
-LINK ?= flock $(builddir)/linker.lock $(CXX) %(LINK_flags)s
+LINK ?= $(CXX) %(LINK_flags)s
 
 CC.target ?= $(CC)
 CFLAGS.target ?= $(CFLAGS)
@@ -129,13 +129,13 @@
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
 
 # Flags to make gcc output dependency info.  Note that you need to be
