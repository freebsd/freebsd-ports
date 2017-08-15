--- lib/support/mkquota.c.orig	2017-07-24 19:15:39 UTC
+++ lib/support/mkquota.c
@@ -10,6 +10,7 @@
 #include <errno.h>
 #include <string.h>
 #include <fcntl.h>
+#include <inttypes.h>
 
 #include "ext2fs/ext2_fs.h"
 #include "ext2fs/ext2fs.h"
@@ -523,8 +524,8 @@ static int scan_dquots_callback(struct d
 	if (dq->dq_dqb.dqb_curspace != dquot->dq_dqb.dqb_curspace ||
 	    dq->dq_dqb.dqb_curinodes != dquot->dq_dqb.dqb_curinodes) {
 		scan_data->usage_is_inconsistent = 1;
-		fprintf(stderr, "[QUOTA WARNING] Usage inconsistent for ID %u:"
-			"actual (%ld, %ld) != expected (%ld, %ld)\n",
+		fprintf(stderr, "[QUOTA WARNING] Usage inconsistent for ID %" PRIu32 ":"
+			"actual (%" PRId64 ", %" PRId64 ") != expected (%" PRId64 ", %" PRId64 ")\n",
 			dq->dq_id, dq->dq_dqb.dqb_curspace,
 			dq->dq_dqb.dqb_curinodes,
 			dquot->dq_dqb.dqb_curspace,
