--- generic/maildriver_tools.c.orig	Tue Dec  9 00:36:37 2003
+++ generic/maildriver_tools.c	Thu Dec 11 00:01:00 2003
@@ -40,6 +40,7 @@
 #include <string.h>
 #include <dirent.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "maildriver.h"
 #include "mailmessage.h"
