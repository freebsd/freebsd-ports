--- insthier.c.orig	Mon Jun 10 21:12:06 2002
+++ insthier.c	Mon Sep 29 09:33:34 2003
@@ -1,18 +1,11 @@
-#include <installer.h>
+#include </usr/local/include/bglibs/installer.h>
 #include "conf_bin.c"
-#include "conf_man.c"
 
 void insthier(void)
 {
   int bin = opendir(conf_bin);
-  int man = opendir(conf_man);
-  int man1;
 
   c(bin, "unixcat",    -1, -1, 0755);
   c(bin, "unixclient", -1, -1, 0755);
   c(bin, "unixserver", -1, -1, 0755);
-
-  man1 = d(man, "man1", -1, -1, 0755);
-  c(man1, "unixclient.1", -1, -1, 0644);
-  c(man1, "unixserver.1", -1, -1, 0644);
 }
