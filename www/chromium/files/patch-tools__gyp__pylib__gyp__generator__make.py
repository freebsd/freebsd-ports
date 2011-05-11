--- tools/gyp/pylib/gyp/generator/make.py.orig	2011-04-26 11:14:32.000000000 +0300
+++ tools/gyp/pylib/gyp/generator/make.py	2011-05-04 21:12:47.761273429 +0300
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
@@ -249,7 +249,7 @@
 # so we can check their command lines.
 #   $? -- new prerequisites
 #   $| -- order-only dependencies
-prereq_changed = $(filter-out $|,$?)
+prereq_changed = $(filter-out FORCE_DO_CMD $|,$?)
 
 # do_cmd: run a command via the above cmd_foo names, if necessary.
 # Should always run for a given target to handle command-line changes.
