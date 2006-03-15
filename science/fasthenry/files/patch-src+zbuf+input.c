--- src/zbuf/input.c.orig	Sat Feb 25 22:33:42 2006
+++ src/zbuf/input.c	Sat Feb 25 22:34:26 2006
@@ -34,6 +34,7 @@
  
 */
 
+#include <string.h>
 #include "mulGlobal.h"
 #include "zbufGlobal.h"
 
@@ -1462,7 +1463,7 @@
   surface *surf_list, *input_surfaces();
   char infile[BUFSIZ], *ctime(), hostname[BUFSIZ];
   charge *read_panels(), *chglist;
-  long clock;
+  time_t clock;
   extern ITER *kill_num_list, *qpic_num_list, *kinp_num_list, *kq_num_list;
   extern char *kill_name_list, *qpic_name_list, *kinp_name_list;
   extern char *kq_name_list;
