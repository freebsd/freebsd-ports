$FreeBSD$

--- xxdiff.pro.orig	Tue Nov  6 15:00:01 2001
+++ xxdiff.pro	Wed Nov  7 02:22:25 2001
@@ -80,6 +80,12 @@
 solaris-cc:TMAKE_CXXFLAGS += -DCOMPILER_SUNWSPRO
 
 
+#
+# FreeBSD
+#
+freebsd-g++:TMAKE_LIBS += ${PTHREAD_LIBS}
+
+
 # Add diff files to link against directly
 DIFFUTILS_DIR = ../diffutils-2.7
 
