
$FreeBSD$

--- camel/camel-sasl-digest-md5.c	2001/05/16 07:38:17	1.1
+++ camel/camel-sasl-digest-md5.c	2001/05/16 07:38:45
@@ -29,7 +29,7 @@
 #include <ctype.h>
 #include <unistd.h>
 
-#include <iconv.h>
+#include <giconv.h>
 
 #define d(x)
 
