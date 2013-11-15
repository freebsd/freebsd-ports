--- tools/gyp/pylib/gyp/generator/make.py.orig	2013-10-29 15:18:11.000000000 +0900
+++ tools/gyp/pylib/gyp/generator/make.py	2013-10-31 18:48:40.000000000 +0900
@@ -86,7 +86,7 @@
   else:
     operating_system = flavor
     if flavor == 'android':
-      operating_system = 'linux'  # Keep this legacy behavior for now.
+      operating_system = 'freebsd'  # Keep this legacy behavior for now.
     default_variables.setdefault('OS', operating_system)
     default_variables.setdefault('SHARED_LIB_SUFFIX', '.so')
     default_variables.setdefault('SHARED_LIB_DIR','$(builddir)/lib.$(TOOLSET)')
@@ -258,9 +258,9 @@
 CC.target ?= $(CC)
 CFLAGS.target ?= $(CFLAGS)
 CXX.target ?= $(CXX)
-CXXFLAGS.target ?= $(CXXFLAGS)
+CXXFLAGS.target ?= %%GCCCXXFLAGS%% $(CXXFLAGS)
 LINK.target ?= $(LINK)
-LDFLAGS.target ?= $(LDFLAGS)
+LDFLAGS.target ?= %%GCCLDFLAGS%% $(LDFLAGS)
 AR.target ?= $(AR)
 ARFLAGS.target ?= %(ARFLAGS.target)s
 
@@ -268,12 +268,12 @@
 # in gyp's make.py where ARFLAGS.host etc. is computed.
 # TODO(evan): move all cross-compilation logic to gyp-time so we don't need
 # to replicate this environment fallback in make as well.
-CC.host ?= gcc
-CFLAGS.host ?=
-CXX.host ?= g++
-CXXFLAGS.host ?=
-LINK.host ?= g++
-LDFLAGS.host ?=
+CC.host ?= $(CC)
+CFLAGS.host ?= $(CFLAGS)
+CXX.host ?= $(CXX)
+CXXFLAGS.host ?= %%GCCCXXFLAGS%% $(CXXFLAGS)
+LINK.host ?= $(LINK)
+LDFLAGS.host ?= %%GCCLDFLAGS%% $(LDFLAGS)
 AR.host ?= ar
 ARFLAGS.host := %(ARFLAGS.host)s
 
@@ -1750,7 +1750,7 @@
       return modules
 
     # Retrieve the default value of 'SHARED_LIB_SUFFIX'
-    params = {'flavor': 'linux'}
+    params = {'flavor': 'freebsd'}
     default_variables = {}
     CalculateVariables(default_variables, params)
 
