--- mailsync.c.orig	Thu Nov  7 12:05:46 2002
+++ mailsync.c	Mon Feb  3 22:59:09 2003
@@ -30,8 +30,8 @@
 using std::vector;
 using std::make_pair;
 
-#include "c-client.h"
-#include "flstring.h"
+#include <c-client.h>
+#include <flstring.h>
 #include "msgstring.c"
 
 //------------------------------- Defines  -------------------------------
