--- src/local.c.orig	Mon May 19 22:44:46 2003
+++ src/local.c	Wed Aug  4 04:15:10 2004
@@ -19,6 +19,7 @@
 #include "masqmail.h"
 #include "peopen.h"
 #include <sys/wait.h>
+#include <sys/stat.h>
 
 static
 void message_stream(FILE *out, message *msg, GList *hdr_list, guint flags)
