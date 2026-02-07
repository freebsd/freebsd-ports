--- include/afpfs-ng/map_def.h.orig	1970-01-01 00:00:00.000000000 +0000
+++ include/afpfs-ng/map_def.h	2012-10-14 13:11:34.000000000 +0000
@@ -0,0 +1,15 @@
+#ifndef __MAP_H_
+#define __MAP_H_
+
+#include "afpfs-ng/afp.h"
+
+#define AFP_MAPPING_UNKNOWN 0
+#define AFP_MAPPING_COMMON 1
+#define AFP_MAPPING_LOGINIDS 2
+#define AFP_MAPPING_NAME 3
+
+unsigned int map_string_to_num(char * name);
+char * get_mapping_name(struct afp_volume * volume);
+
+
+#endif
diff -Naur afpfs-ng-0.8.1.orig/include/afpfs-ng/midlevel.h afpfs-ng-0.8.1/include/afpfs-ng/midlevel.h
