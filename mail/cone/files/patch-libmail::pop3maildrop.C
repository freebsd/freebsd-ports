--- libmail/pop3maildrop.C.orig	Sun Nov 16 03:43:14 2003
+++ libmail/pop3maildrop.C	Sat Nov 29 04:29:03 2003
@@ -13,6 +13,8 @@
 #include <errno.h>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 using namespace std;
 
