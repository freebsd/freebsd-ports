--- Makefile.m4_old	Mon Jun 16 12:46:31 2003
+++ Makefile.m4	Mon Jun 16 12:46:56 2003
@@ -5,10 +5,10 @@
 dvd+rw-tools:	$(CHAIN)
 
 WARN=#-Wall	# developers are welcomed to build with `make WARN=-Wall'
-CC=gcc
-CFLAGS=$(WARN) -O2
-CXX=g++
-CXXFLAGS=$(WARN) -O2 -fno-exceptions
+CC ?= gcc
+CFLAGS ?= $(WARN) -O2
+CXX ?= g++
+CXXFLAGS ?=$(WARN) -O2 -fno-exceptions
 '
 ifelse(OS,NetBSD,`define(`OS',`BSD')')
 ifelse(OS,OpenBSD,`define(`OS',`BSD')')
@@ -27,7 +27,7 @@
 	$(CXX) $(CXXFLAGS) -o $@ $> $^ $(LDFLAGS) $(LDLIBS)
 
 install:	dvd+rw-tools
-	install -o root -m 04755 $(CHAIN) /usr/local/bin
+	install -o root -m 0755 $(CHAIN) /usr/local/bin
 ')
 ifelse(OS,SunOS,`
 #
