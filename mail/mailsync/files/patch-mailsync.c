--- mailsync.c.orig	Thu Nov  7 12:05:46 2002
+++ mailsync.c	Wed Jul 14 03:52:22 2004
@@ -20,6 +20,7 @@
 extern int errno;               // Just in case
 #include <sys/stat.h>           // Stat()
 
+#include <cassert>
 #include <string>
 #include <set>
 #include <map>
@@ -30,8 +31,8 @@
 using std::vector;
 using std::make_pair;
 
-#include "c-client.h"
-#include "flstring.h"
+#include <c-client.h>
+#include <flstring.h>
 #include "msgstring.c"
 
 //------------------------------- Defines  -------------------------------
