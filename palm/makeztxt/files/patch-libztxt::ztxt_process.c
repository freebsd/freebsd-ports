--- libztxt/ztxt_process.c.orig	Sat Mar  2 07:03:18 2002
+++ libztxt/ztxt_process.c	Sat Aug 14 13:35:00 2004
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <zlib.h>
 #include "ztxt.h"
@@ -140,7 +141,7 @@
             break;
 
           case 2:
-          default:
+          default:;
             /* Just leave the next alone.  No linefeed stripping. */
         }
 
