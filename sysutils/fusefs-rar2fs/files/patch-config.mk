$FreeBSD$

Automatically fills in the correct areas in config.mk with FreeBSD-sane
defaults.  Sed is used to correct the substitutions.

--- config.mk.orig	2011-05-17 21:17:09.000000000 +0200
+++ config.mk	2011-05-30 14:11:09.689753703 +0200
@@ -1,37 +1,39 @@
 # Change below to match current configuration
 ##########################
 
+DESTDIR=%%PREFIX%%
+
 ##########################
 # This is the path (absolute or relative) to the folder containing
 # the full portable "Unrar C++ library" (libunrar) sources 
-UNRAR_SRC=./unrar
+UNRAR_SRC=../unrar
 
 ##########################
 # This is the path (absolute or relative) to the folder containing
 # the compiled libunrar.so.
 # This can be left blank if the system already points out the location
 # of a compatible unrarlib.so, eg. /lib.
-UNRAR_LIB=
+UNRAR_LIB=%%LOCALBASE%%/lib
 
 ##########################
 # This is the path (absolute or relative) to the folder containing
 # the FUSE development header files.
 # This can be left blank if the header files are already placed in
 # some default location such as /usr/include.
-FUSE_SRC=
+FUSE_SRC=%%LOCALBASE%%/include
 
 ##########################
 # This is the path (absolute or relative) to the folder containing
 # the FUSE library files.
 # This can be left blank if the system already points out the location
 # of a compatible FUSE library, eg. /lib.
-FUSE_LIB=
+FUSE_LIB=%%LOCALBASE%%/lib
 
 ##########################
 # Does the host support glibc custom streams?
 # If unsure try 'y' here. If linker fails to find e.g. fmemopen()
 # your answer was most likely incorrect.
-HAS_GLIBC_CUSTOM_STREAMS=y
+HAS_GLIBC_CUSTOM_STREAMS=n
 
 ##########################
 # For Mac OS X, choose if 64-bit inodes (file serial number) should
