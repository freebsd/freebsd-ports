--- tools/gyp/pylib/gyp/generator/make.py.orig	2011-07-28 11:18:03.000000000 +0300
+++ tools/gyp/pylib/gyp/generator/make.py	2011-09-07 01:20:36.000000000 +0300
@@ -239,13 +239,13 @@
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
@@ -365,7 +365,7 @@
 # so we can check their command lines.
 #   $? -- new prerequisites
 #   $| -- order-only dependencies
-prereq_changed = $(filter-out $|,$?)
+prereq_changed = $(filter-out FORCE_DO_CMD $|,$?)
 
 # do_cmd: run a command via the above cmd_foo names, if necessary.
 # Should always run for a given target to handle command-line changes.
