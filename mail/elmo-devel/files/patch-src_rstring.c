$FreeBSD$

--- src/rstring.c.orig	Sat Sep  6 01:58:14 2003
+++ src/rstring.c	Sun Sep 28 02:57:41 2003
@@ -29,7 +29,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <regex.h>
 #include <errno.h>
 #include <ctype.h>
 
@@ -37,6 +36,7 @@
 #include "rarray.h"
 #include "rstring.h"
 #include "error.h"
+#include <regex.h>
 #include "memchunk.h"
 
 /****************************************************************************
