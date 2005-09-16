--- /dev/null	Mon Feb 16 12:56:01 2004
+++ datescan.c	Mon Feb 16 12:55:18 2004
@@ -0,0 +1,88 @@
+#include "dates.h"
+enum DATESCAN_TYPE datescan_exitval[] = {
+DS_FAILURE, /* State 0 */
+DS_FAILURE, /* State 1 */
+DS_D, /* State 2 */
+DS_D, /* State 3 */
+DS_D, /* State 4 */
+DS_FAILURE, /* State 5 */
+DS_Y, /* State 6 */
+DS_SCALED, /* State 7 */
+DS_D, /* State 8 */
+DS_SCALED, /* State 9 */
+DS_Y, /* State 10 */
+DS_FAILURE, /* State 11 */
+DS_FAILURE, /* State 12 */
+DS_SCALED, /* State 13 */
+DS_FAILURE, /* State 14 */
+DS_FAILURE, /* State 15 */
+DS_M, /* State 16 */
+DS_FAILURE, /* State 17 */
+DS_FAILURE, /* State 18 */
+DS_Y, /* State 19 */
+DS_DM, /* State 20 */
+DS_FAILURE, /* State 21 */
+DS_MD, /* State 22 */
+DS_MD, /* State 23 */
+DS_MD, /* State 24 */
+DS_FAILURE, /* State 25 */
+DS_YM, /* State 26 */
+DS_FAILURE, /* State 27 */
+DS_FAILURE, /* State 28 */
+DS_FAILURE, /* State 29 */
+DS_FAILURE, /* State 30 */
+DS_MY, /* State 31 */
+DS_MD, /* State 32 */
+DS_MY, /* State 33 */
+DS_YYMMDD, /* State 34 */
+DS_YMD, /* State 35 */
+DS_YMD, /* State 36 */
+DS_YMD, /* State 37 */
+DS_DMY, /* State 38 */
+DS_FAILURE, /* State 39 */
+DS_DMY, /* State 40 */
+DS_FAILURE, /* State 41 */
+DS_YYMMDD, /* State 42 */
+DS_FAILURE  /* State 43 */
+};
+
+static short datescan_trans[] = {
+     1,    2,    2,    3,    4,    5,    6,    6,
+     6,    6,    6,    7,    8,    8,    8,    8,
+     8,    9,    8,    8,   10,   10,   10,    9,
+    10,   10,   10,   10,   10,    9,   -1,   -1,
+    -1,   -1,   -1,   11,   12,   12,   12,   12,
+    12,   13,   -1,   -1,   -1,   -1,   -1,   -1,
+    14,   14,   14,   14,   14,    9,   -1,   -1,
+    -1,   -1,   -1,   15,   14,   14,   14,   14,
+    14,   13,   -1,   -1,   -1,   -1,   -1,   16,
+    17,   17,   17,   17,   17,    7,   -1,   -1,
+    -1,   -1,   -1,   18,   19,   19,   19,   19,
+    19,    7,   -1,   -1,   -1,   -1,   -1,   20,
+    21,   22,   22,   23,   24,   -1,   25,   25,
+    25,   25,   25,    7,   -1,   -1,   -1,   -1,
+    -1,   26,   25,   25,   25,   25,   25,   13,
+    27,   28,   28,   29,   30,   -1,   31,   31,
+    31,   31,   31,   -1,   32,   32,   32,   32,
+    32,   -1,   32,   32,   33,   33,   33,   -1,
+    33,   33,   33,   33,   33,   -1,   34,   34,
+    34,   34,   34,    7,   -1,   35,   35,   36,
+    37,   -1,   38,   38,   38,   38,   38,   -1,
+    39,   39,   39,   39,   39,   -1,   39,   39,
+    40,   40,   40,   -1,   40,   40,   40,   40,
+    40,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    21,   21,   21,   21,   21,   -1,   21,   21,
+    21,   21,   21,   -1,   41,   41,   41,   41,
+    41,    7,   37,   37,   37,   37,   37,   -1,
+    37,   37,   -1,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   27,   27,   27,   27,   27,   -1,
+    27,   27,   27,   27,   27,   -1,   42,   42,
+    42,   42,   42,    7,   43,   43,   43,   43,
+    43,    7,   43,   43,   43,   43,   43,    7
+};
+
+int datescan_next_state(int current_state, int next_token) {
+  if (next_token < 0 || next_token >= 6) return -1;
+  return datescan_trans[6*current_state + next_token];
+}
