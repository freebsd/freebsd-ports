
$FreeBSD$

--- libmutt/charset.c	2001/03/06 10:39:57	1.1
+++ libmutt/charset.c	2001/03/06 10:40:07
@@ -29,7 +29,7 @@
 #include <unistd.h>
 #include <errno.h>
 
-#include <iconv.h>
+#include <giconv.h>
 
 #include "mutt.h"
 #include "charset.h"
