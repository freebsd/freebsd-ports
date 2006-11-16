--- cherokee/connection.c.orig	Wed Aug 30 17:12:13 2006
+++ cherokee/connection.c	Thu Nov 16 00:41:26 2006
@@ -33,6 +33,9 @@
 #include <time.h>
 #include <sys/types.h>
 
+#include <stdlib.h>
+#include <limits.h>
+
 #ifdef HAVE_PWD_H
 # include <pwd.h>
 #endif
@@ -1210,7 +1213,7 @@
 	}
 	tmp[num_len] = '\0';
 	if (num_len != 0) {
-		cnt->range_start = atoll (tmp);
+		cnt->range_start = strtoll(tmp, (char **)NULL, 10);
 		if (cnt->range_start < 0) {
 			return ret_error;
 		}
@@ -1236,7 +1239,7 @@
 			num_len++;
 		}
 		tmp[num_len] = '\0';
-		cnt->range_end = atoll (tmp);
+		cnt->range_end = strtoll(tmp, (char **)NULL, 10);
 		if (cnt->range_end < 1){
 			return ret_error;
 		}
