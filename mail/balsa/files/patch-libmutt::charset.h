
$FreeBSD$

--- libmutt/charset.h	2001/03/06 10:38:56	1.1
+++ libmutt/charset.h	2001/03/06 10:39:08
@@ -19,7 +19,7 @@
 #ifndef _CHARSET_H
 #define _CHARSET_H
 
-#include <iconv.h>
+#include <giconv.h>
 
 int mutt_convert_string (char **, const char *, const char *);
 
