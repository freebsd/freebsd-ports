
$FreeBSD$

--- CfgFileParser.cc.orig	Tue Aug  3 21:40:44 1999
+++ CfgFileParser.cc	Tue Nov 26 01:08:21 2002
@@ -20,11 +20,10 @@
 #include "CfgFileParser.h"
 
 #include <stdio.h>
-#include <fstream.h>
+#include <iostream.h>
 #include <assert.h>
 #include <string.h>
-#include <malloc.h>
-
+#include <stdlib.h>
 
 // ## class SearchData ##
 
