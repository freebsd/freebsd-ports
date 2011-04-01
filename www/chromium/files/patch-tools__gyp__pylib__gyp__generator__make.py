--- ./tools/gyp/pylib/gyp/generator/make.py.orig	2010-12-16 02:33:33.000000000 +0100
+++ ./tools/gyp/pylib/gyp/generator/make.py	2010-12-20 20:15:08.000000000 +0100
@@ -106,7 +106,7 @@
 #   export LINK="$(CXX)"
 #
 # This will allow make to invoke N linker processes as specified in -jN.
-LINK ?= flock $(builddir)/linker.lock $(CXX)
+LINK ?= $(CXX)
 
 # We want to use GNU ar's T option if available because it's much faster.
 # We try to archive and link a file to see ar and ld support this feature.
@@ -147,13 +147,13 @@
   ARFLAGS.target := $(call detect_arflags,target)
 endif
 
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
 # See the description for ARFLAGS.target.
 -include $(obj).host/arflags/arflags.mk
 # Temporarily disabled -- see ARFLAGS.target.
