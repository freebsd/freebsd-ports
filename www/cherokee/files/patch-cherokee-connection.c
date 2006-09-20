--- cherokee/connection.c.orig	Wed Sep 20 21:17:53 2006
+++ cherokee/connection.c	Wed Sep 20 21:17:53 2006
@@ -33,6 +33,12 @@
 #include <time.h>
 #include <sys/types.h>
 
+#undef fr_atoll
+#define fr_atoll(nptr) strtoll(nptr, (char **)NULL, 10)
+
+#include <stdlib.h>
+#include <limits.h>
+
 #ifdef HAVE_PWD_H
 # include <pwd.h>
 #endif
@@ -1210,7 +1216,7 @@
 	}
 	tmp[num_len] = '\0';
 	if (num_len != 0) {
-		cnt->range_start = atoll (tmp);
+		cnt->range_start = fr_atoll (tmp);
 		if (cnt->range_start < 0) {
 			return ret_error;
 		}
@@ -1236,7 +1242,7 @@
 			num_len++;
 		}
 		tmp[num_len] = '\0';
-		cnt->range_end = atoll (tmp);
+		cnt->range_end = fr_atoll (tmp);
 		if (cnt->range_end < 1){
 			return ret_error;
 		}
