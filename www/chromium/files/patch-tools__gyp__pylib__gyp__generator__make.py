--- tools/gyp/pylib/gyp/generator/make.py.orig	2012-11-27 10:03:58.000000000 +0200
+++ tools/gyp/pylib/gyp/generator/make.py	2012-12-10 22:26:33.000000000 +0200
@@ -86,7 +86,7 @@
   else:
     operating_system = flavor
     if flavor == 'android':
-      operating_system = 'linux'  # Keep this legacy behavior for now.
+      operating_system = 'freebsd'  # Keep this legacy behavior for now.
     default_variables.setdefault('OS', operating_system)
     default_variables.setdefault('SHARED_LIB_SUFFIX', '.so')
     default_variables.setdefault('SHARED_LIB_DIR','$(builddir)/lib.$(TOOLSET)')
@@ -250,30 +250,30 @@
 CFLAGS.target ?= $(CFLAGS)
 CXX.target ?= %(CXX.target)s
 CXXFLAGS.target ?= $(CXXFLAGS)
-LINK.target ?= %(LINK.target)s
+LINK.target ?= %(CXX.target)s
 LDFLAGS.target ?= $(LDFLAGS)
 AR.target ?= $(AR)

 # C++ apps need to be linked with g++.
 #
 # Note: flock is used to seralize linking. Linking is a memory-intensive
 # process so running parallel links can often lead to thrashing.  To disable
 # the serialization, override LINK via an envrionment variable as follows:
 #
 #   export LINK=g++
 #
 # This will allow make to invoke N linker processes as specified in -jN.
 LINK ?= %(flock)s $(builddir)/linker.lock $(CXX.target)

 # TODO(evan): move all cross-compilation logic to gyp-time so we don't need
 # to replicate this environment fallback in make as well.
-CC.host ?= %(CC.host)s
-CFLAGS.host ?=
-CXX.host ?= %(CXX.host)s
-CXXFLAGS.host ?=
-LINK.host ?= %(LINK.host)s
-LDFLAGS.host ?=
-AR.host ?= %(AR.host)s
+CC.host ?= $(CC)
+CFLAGS.host ?= $(CFLAGS)
+CXX.host ?= $(CXX)
+CXXFLAGS.host ?= $(CXXFLAGS)
+LINK.host ?= $(CXX)
+LDFLAGS.host ?= $(LDFLAGS)
+AR.host ?= $(AR)
 
 # Define a dir function that can handle spaces.
 # http://www.gnu.org/software/make/manual/make.html#Syntax-of-Functions
@@ -1770,7 +1770,7 @@
       return modules
 
     # Retrieve the default value of 'SHARED_LIB_SUFFIX'
-    params = {'flavor': 'linux'}
+    params = {'flavor': 'freebsd'}
     default_variables = {}
     CalculateVariables(default_variables, params)
 
