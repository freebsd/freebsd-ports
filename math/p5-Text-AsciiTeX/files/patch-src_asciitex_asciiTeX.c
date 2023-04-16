--- src/asciitex/asciiTeX.c.orig	2023-04-16 15:12:02 UTC
+++ src/asciitex/asciiTeX.c
@@ -38,6 +38,7 @@
 #include "dim.h"
 #include "utils.h"
 
+STAT SYNTAX_ERR_FLAG;
 char ** messages;
 int Nmes;
 int Nall;
