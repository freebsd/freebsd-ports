--- configuration.h.orig	Sun Mar 20 11:17:12 2005
+++ configuration.h	Sun Mar 20 08:57:43 2005
@@ -6,6 +6,7 @@
   int max_concurrent_dumps;
   gboolean daemon;
   char *pidfile;
+  char *dumpdirprefix;
   int secure;
   int space_check;
 } NetdumpConfiguration;
