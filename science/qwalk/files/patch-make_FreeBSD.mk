--- make/FreeBSD.mk.orig	2018-08-21 01:16:34 UTC
+++ make/FreeBSD.mk
@@ -0,0 +1,26 @@
+######################################################################
+# Compiler definitions for Linux systems
+#  all compiler specific information should be declared here
+
+
+CXX?=c++
+F77?=gfortran
+
+CXXFLAGS += \
+   -funroll-loops -ffast-math \
+  $(INCLUDEPATH) -fomit-frame-pointer
+
+
+DEBUG:= -Wall -DNO_RANGE_CHECKING -DNDEBUG    -DDEBUG_WRITE
+LDFLAGS:= 
+
+HDF_LIBS=-lhdf5
+#HDF_INCLUDE=
+
+XML_LIBS:=$(shell xml2-config --libs)
+XML_INCLUDE:=$(shell xml2-config --cflags)
+
+######################################################################
+# This is the invokation to generate dependencies
+DEPENDMAKER:=c++ -MM  $(INCLUDEPATH)
+
