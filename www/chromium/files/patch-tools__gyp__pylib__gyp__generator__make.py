--- tools/gyp/pylib/gyp/generator/make.py.orig	2016-01-21 16:48:10.674923813 +0100
+++ tools/gyp/pylib/gyp/generator/make.py	2016-01-21 16:52:28.811903889 +0100
@@ -276,7 +276,7 @@
 CFLAGS.target ?= $(CPPFLAGS) $(CFLAGS)
 CXX.target ?= %(CXX.target)s
 CXXFLAGS.target ?= $(CPPFLAGS) $(CXXFLAGS)
-LINK.target ?= %(LINK.target)s
+LINK.target ?= %(CXX.target)s
 LDFLAGS.target ?= $(LDFLAGS)
 AR.target ?= $(AR)
 
@@ -285,13 +285,13 @@
 
 # TODO(evan): move all cross-compilation logic to gyp-time so we don't need
 # to replicate this environment fallback in make as well.
-CC.host ?= %(CC.host)s
-CFLAGS.host ?= $(CPPFLAGS_host) $(CFLAGS_host)
-CXX.host ?= %(CXX.host)s
-CXXFLAGS.host ?= $(CPPFLAGS_host) $(CXXFLAGS_host)
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
@@ -1816,7 +1816,7 @@
       return modules
 
     # Retrieve the default value of 'SHARED_LIB_SUFFIX'
-    params = {'flavor': 'linux'}
+    params = {'flavor': 'freebsd'}
     default_variables = {}
     CalculateVariables(default_variables, params)
 
