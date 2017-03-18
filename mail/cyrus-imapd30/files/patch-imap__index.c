--- imap/index.c.orig	2017-03-17 04:11:35 UTC
+++ imap/index.c
@@ -53,8 +53,10 @@
 #include <ctype.h>
 #include <stdlib.h>
 
+#ifdef USE_HTTPD
 /* For iCalendar indexing */
 #include <libical/ical.h>
+#endif
 
 #include "acl.h"
 #include "annotate.h"
