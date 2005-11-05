--- src/utils.c.orig	Fri May  6 16:10:28 2005
+++ src/utils.c	Sun Jul  3 17:48:12 2005
@@ -24,6 +24,8 @@
    on GNOME 2.0 */
 
 #include "utils.h"
+#include <stdlib.h>
+#include <limits.h>
 #include <string.h>
 #include <glib/gi18n.h>
 
@@ -240,7 +242,7 @@ util_legible_bytes (gchar *bytes)
 	const gchar *unit = "B";
 	gchar *result;
 	
-	sscanf (bytes, "%lld", &rx);
+	rx = strtoull (bytes, (char **)NULL, 10);
 	short_rx = rx * 10;  
 
 	if (rx > 1125899906842624ull) {
