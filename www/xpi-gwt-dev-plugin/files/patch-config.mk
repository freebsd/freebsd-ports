diff -u /tmp/gwt-plugins-release-2.0/config.mk config.mk
--- /tmp/gwt-plugins-release-2.0/config.mk	2010-01-19 08:52:18.000000000 +1300
+++ ./config.mk	2010-01-11 14:41:49.000000000 +1300
@@ -32,6 +32,9 @@
 FLAG32BIT=32
 
 # Figure out 64-bit platforms, canonicalize ARCH and MARCH
+ifeq ($(ARCH),amd64)
+FLAG32BIT=64
+endif
 ifeq ($(ARCH),x86_64)
 FLAG32BIT=64
 endif
@@ -76,6 +79,12 @@
 endif
 
 # Set OS as well as CFLAGS, CXX, and other common make variables
+ifeq ($(shell uname),FreeBSD)
+OS=freebsd
+BASECFLAGS= -g -O2 -fPIC $(INC) -rdynamic
+ARCHCFLAGS=-m$(FLAG32BIT)
+ALLARCHCFLAGS=$(ARCHCFLAGS)
+endif
 ifeq ($(shell uname),Linux)
 OS=linux
 BASECFLAGS= -g -O2 -fPIC $(INC) -rdynamic
