--- config.mk.orig	2013-10-17 17:54:13 UTC
+++ config.mk
@@ -8,20 +8,20 @@
 # the Makefiles.
 
 # C++ compiler
-CXX=g++
+CXX?=g++
 
 # Flags for the C++ compiler
-CFLAGS=-Wall -ansi -pedantic -O3
+CFLAGS?=-Wall -ansi -pedantic -O3
 
 # Relative include and library paths for compilation of the examples
 E_INC=-I../../src
 E_LIB=-L../../src
 
 # Installation directory
-PREFIX=/usr/local
+PREFIX?=/usr/local
 
 # Install command
-INSTALL=install
+INSTALL?=install
 
 # Flags for install command for executable
 IFLAGS_EXEC=-m 0755
