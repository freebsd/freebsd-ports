--- src/php7/solr_types.h.orig  2016-03-30 13:42:31 UTC
+++ src/php7/solr_types.h
@@ -53,6 +53,7 @@
 #include <libxml/tree.h>

 typedef unsigned char solr_bool;
+typedef unsigned long   ulong;            /* Short for unsigned long */

 #include "solr_string.h"


