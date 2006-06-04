--- kmess/crypt/globalstuff.h.orig	Fri May 21 04:00:44 2004
+++ kmess/crypt/globalstuff.h	Sun Jun  4 13:48:21 2006
@@ -16,9 +16,9 @@
 
 #include "config.h"
 
+#include <sys/types.h>
 #include <string>
 #include <sstream>
-#include <stdint.h>
 
 /** convert something to string using ostringstream */
 template <class T> inline
