
$FreeBSD$

--- mail/openpgp-utils.c	2001/05/16 07:47:09	1.1
+++ mail/openpgp-utils.c	2001/05/16 07:47:21
@@ -45,7 +45,7 @@
 #include <unistd.h>
 #include <signal.h>
 
-#include <iconv.h>
+#include <giconv.h>
 
 #include <glib.h>
 #include <libgnome/gnome-defs.h>
