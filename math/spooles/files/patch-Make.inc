--- Make.inc.orig	Mon Jan 18 16:48:55 1999
+++ Make.inc	Sun May 11 14:32:36 2003
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
@@ -50,8 +50,8 @@
 #  set any thread libraries
 #
 # THREAD_LIBS =
-# THREAD_LIBS = -D_REENTRANT=199506L -lpthread
-  THREAD_LIBS = -D_POSIX_C_SOURCE=199506L -lpthread
+THREAD_LIBS = -D_REENTRANT=199506L %%PTHREAD_LIBS%%
+# THREAD_LIBS = -D_POSIX_C_SOURCE=199506L -lpthread
 # THREAD_LIBS = -lpthread
 #
 #---------------------------------------------------------------------
@@ -79,15 +79,15 @@
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
 #  set suffix rule *.c --> *.o
 #
-.c.o : 
-	$(PURIFY) $(CC) -c $(CFLAGS) $<
+#.c.o : 
+#	$(PURIFY) $(CC) -c $(CFLAGS) $<
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
