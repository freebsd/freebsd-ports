--- ./torture/config.mk.orig	2009-01-14 08:31:07.000000000 +0000
+++ ./torture/config.mk	2009-01-19 02:13:34.000000000 +0000
@@ -198,7 +198,7 @@
 
 #################################
 # Start BINARY smbtorture
-[BINARY::smbtorture]
+[BINARY::smbtorture4]
 INSTALLDIR = BINDIR
 PRIVATE_PROTO_HEADER = torture.h
 OBJ_FILES = \
