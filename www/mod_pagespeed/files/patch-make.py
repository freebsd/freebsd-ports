--- tools/gyp/pylib/gyp/generator/make.py.orig	2011-09-29 21:00:14.000000000 +0000
+++ tools/gyp/pylib/gyp/generator/make.py	2011-09-29 21:00:28.000000000 +0000
@@ -153,11 +153,11 @@
   ARFLAGS.target := $(call detect_arflags,target)
 endif
 
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
 # See the description for ARFLAGS.target.
