--- Make.inc.orig	Tue Jan 19 06:48:55 1999
+++ Make.inc	Mon May  5 09:59:52 2003
@@ -12,7 +12,7 @@
 # for solaris
 #
 # CC = gcc
-  CC = /usr/lang-4.0/bin/cc
+# CC = cc
 #
 # for sgi
 #
@@ -28,14 +28,14 @@
 # 
 # OPTLEVEL = 
 # OPTLEVEL = -g -v
-  OPTLEVEL = -O
+# OPTLEVEL = -O
 # OPTLEVEL = -xO5 -v
 # OPTLEVEL = -O3
 # OPTLEVEL = -O4
 # CFLAGS = -Wall -g
 # CFLAGS = -Wall -pg
 # CFLAGS = $(OPTLEVEL) -D_POSIX_C_SOURCE=199506L
-  CFLAGS = $(OPTLEVEL)
+# CFLAGS += $(OPTLEVEL)
 # CFLAGS = -Wall $(OPTLEVEL)
 #
 #----------------------------------------
@@ -79,8 +79,8 @@
 #  set the ranlib environment
 #  (if ranlib is not needed, we echo the library name)
 #
-# RANLIB = ranlib
-  RANLIB = echo
+  RANLIB = ranlib
+# RANLIB = echo
 #
 #---------------------------------------------------------------------
 #
@@ -103,7 +103,7 @@
 #  MPI install library
 #
 # MPI_INSTALL_DIR = 
-  MPI_INSTALL_DIR = /usr/local/mpich-1.0.13
+MPI_INSTALL_DIR = %%LOCALBASE%%/mpich
 #
 #---------------------------------------------------------------------
 #
@@ -115,7 +115,7 @@
 #
 # for solaris
 #
-  MPI_LIB_PATH = -L$(MPI_INSTALL_DIR)/lib/solaris/ch_p4
+MPI_LIB_PATH = -L$(MPI_INSTALL_DIR)/lib
 #
 # for hp
 #
