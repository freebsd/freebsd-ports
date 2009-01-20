--- ./lib/ldb/config.mk.orig	2009-01-14 08:31:07.000000000 +0000
+++ ./lib/ldb/config.mk	2009-01-19 02:13:34.000000000 +0000
@@ -179,7 +179,7 @@
 
 ################################################
 # Start BINARY ldbadd
-[BINARY::ldbadd]
+[BINARY::ldbadd4]
 INSTALLDIR = BINDIR
 OBJ_FILES = \
 		tools/ldbadd.o
@@ -191,7 +191,7 @@
 
 ################################################
 # Start BINARY ldbdel
-[BINARY::ldbdel]
+[BINARY::ldbdel4]
 INSTALLDIR = BINDIR
 OBJ_FILES= \
 		tools/ldbdel.o
@@ -203,7 +203,7 @@
 
 ################################################
 # Start BINARY ldbmodify
-[BINARY::ldbmodify]
+[BINARY::ldbmodify4]
 INSTALLDIR = BINDIR
 OBJ_FILES= \
 		tools/ldbmodify.o
@@ -215,7 +215,7 @@
 
 ################################################
 # Start BINARY ldbsearch
-[BINARY::ldbsearch]
+[BINARY::ldbsearch4]
 INSTALLDIR = BINDIR
 OBJ_FILES= \
 		tools/ldbsearch.o
@@ -227,7 +227,7 @@
 
 ################################################
 # Start BINARY ldbedit
-[BINARY::ldbedit]
+[BINARY::ldbedit4]
 INSTALLDIR = BINDIR
 OBJ_FILES= \
 		tools/ldbedit.o
@@ -239,7 +239,7 @@
 
 ################################################
 # Start BINARY ldbrename
-[BINARY::ldbrename]
+[BINARY::ldbrename4]
 INSTALLDIR = BINDIR
 OBJ_FILES= \
 		tools/ldbrename.o
