--- rpcc/scan.ll.orig	Sat Jan 27 03:43:23 2001
+++ rpcc/scan.ll	Sun Dec  1 23:45:45 2002
@@ -1,5 +1,5 @@
 /* -*-fundamental-*- */
-/* $Id: scan.ll,v 1.7 1999/11/03 15:43:14 dm Exp $ */
+/* $Id: scan.ll,v 1.8 2002/10/23 21:02:33 dm Exp $ */
 
 /*
  *
@@ -23,6 +23,7 @@
  */
 
 %{
+#define YYSTYPE YYSTYPE
 #include "rpcc.h"
 #include "parse.h"
 
