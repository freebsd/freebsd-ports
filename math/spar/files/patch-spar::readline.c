--- text-fe/readline.c.orig	Fri Jun  1 11:25:10 2001
+++ text-fe/readline.c	Fri Jun  1 11:25:24 2001
@@ -30,6 +30,7 @@
 #include "cmd_table.h"
 
 #ifdef HAVE_READLINE_HISTORY_H
+#include <stdio.h>
 #include <readline/history.h>
 
 int
