--- src/local.c.old	Fri Apr 30 15:32:04 2004
+++ src/local.c	Fri Apr 30 15:34:23 2004
@@ -19,6 +19,9 @@
 #include "masqmail.h"
 #include "peopen.h"
 #include <sys/wait.h>
+#ifdef ENABLE_MAILDIR
+#include <sys/stat.h>
+#endif
 
 static
 void message_stream(FILE *out, message *msg, GList *hdr_list, guint flags)
