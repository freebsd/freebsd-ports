--- config/config.mk.orig	Wed Nov  4 21:33:23 1998
+++ config/config.mk	Sun Jan  7 19:28:46 2001
@@ -39,7 +39,7 @@
 #	RM	The command to remove files recursively and ignore errors;
 #		usually "rm -fr".
 ##
-MAKE=		make
+MAKE=		gmake
 SHELL=		/bin/sh
 STRIP=		strip
 RM=		rm -fr
@@ -55,7 +55,7 @@
 #			digit after the O for optimization level.
 ##
 CC=		gcc
-CCFLAGS=	-g #-O3 #-g
+CCFLAGS=	-g -O #-g
 
 ##
 # install
@@ -71,7 +71,7 @@
 #	MKDIR	Command used to create a directory.
 ##
 INSTALL=	$(ROOT)/install-sh
-I_ROOT=		/usr/local/txt2pdbdoc
+I_ROOT=		/usr/local
 I_BIN=		$(I_ROOT)/bin
 I_MAN=		$(I_ROOT)/man
 I_OWNER=	-o bin
