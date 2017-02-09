--- iflib/config.h.orig	1997-04-26 09:56:16 UTC
+++ iflib/config.h
@@ -1,6 +1,7 @@
 #ifndef _CONFIG_H
 #define _CONFIG_H
 
+#include <sys/types.h>
 #include "ftn.h"
 
 #ifndef AREA_LIST_TYPE
@@ -53,7 +54,7 @@ extern modem_string *options;
 extern area_list *badgroups;
 
 extern long configverbose;
-extern long configtime;
+extern time_t configtime;
 extern long maxfsize;
 extern long maxpsize;
 extern long maxmsize;
