--- /dev/null	Mon Feb 16 13:00:10 2004
+++ fromcheck.c	Mon Feb 16 13:00:13 2004
@@ -0,0 +1,106 @@
+#include "fromcheck.h"
+enum fromcheck_result fromcheck_exitval[] = {
+FROMCHECK_FAIL, /* State 0 */
+FROMCHECK_FAIL, /* State 1 */
+FROMCHECK_FAIL, /* State 2 */
+FROMCHECK_FAIL, /* State 3 */
+FROMCHECK_FAIL, /* State 4 */
+FROMCHECK_FAIL, /* State 5 */
+FROMCHECK_FAIL, /* State 6 */
+FROMCHECK_FAIL, /* State 7 */
+FROMCHECK_FAIL, /* State 8 */
+FROMCHECK_FAIL, /* State 9 */
+FROMCHECK_FAIL, /* State 10 */
+FROMCHECK_FAIL, /* State 11 */
+FROMCHECK_FAIL, /* State 12 */
+FROMCHECK_FAIL, /* State 13 */
+FROMCHECK_FAIL, /* State 14 */
+FROMCHECK_FAIL, /* State 15 */
+FROMCHECK_FAIL, /* State 16 */
+FROMCHECK_FAIL, /* State 17 */
+FROMCHECK_FAIL, /* State 18 */
+FROMCHECK_FAIL, /* State 19 */
+FROMCHECK_FAIL, /* State 20 */
+FROMCHECK_FAIL, /* State 21 */
+FROMCHECK_FAIL, /* State 22 */
+FROMCHECK_FAIL, /* State 23 */
+FROMCHECK_FAIL, /* State 24 */
+FROMCHECK_FAIL, /* State 25 */
+FROMCHECK_FAIL, /* State 26 */
+FROMCHECK_FAIL, /* State 27 */
+FROMCHECK_FAIL, /* State 28 */
+FROMCHECK_FAIL, /* State 29 */
+FROMCHECK_FAIL, /* State 30 */
+FROMCHECK_FAIL, /* State 31 */
+FROMCHECK_FAIL, /* State 32 */
+FROMCHECK_FAIL, /* State 33 */
+FROMCHECK_FAIL, /* State 34 */
+FROMCHECK_FAIL, /* State 35 */
+FROMCHECK_FAIL, /* State 36 */
+FROMCHECK_FAIL, /* State 37 */
+FROMCHECK_FAIL, /* State 38 */
+FROMCHECK_FAIL, /* State 39 */
+FROMCHECK_PASS, /* State 40 */
+FROMCHECK_FAIL  /* State 41 */
+};
+
+static short fromcheck_trans[] = {
+    -1,   -1,    1,   -1,   -1,    2,    1,    1,
+     3,    1,   -1,   -1,    1,    4,   -1,   -1,
+     1,    1,    1,    1,   -1,   -1,    1,   -1,
+    -1,    2,    1,    5,    3,    1,   -1,   -1,
+     1,    4,   -1,    6,    1,    1,    1,    1,
+    -1,   -1,    7,   -1,   -1,   -1,    7,    7,
+     7,    7,   -1,   -1,    1,    4,   -1,   -1,
+     8,    1,    1,    1,   -1,   -1,   -1,   -1,
+    -1,    6,   -1,    9,   -1,   -1,   -1,   -1,
+     7,   -1,   -1,    6,    7,    7,    7,    7,
+    -1,   -1,    1,    4,   -1,   -1,   10,    1,
+     1,    1,   -1,   -1,   -1,   -1,   -1,   -1,
+    11,   -1,   -1,   -1,   -1,   -1,    1,    4,
+    -1,   12,    1,    1,    1,    1,   -1,   -1,
+    -1,   -1,   -1,   -1,   13,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   12,   -1,   14,
+    -1,   -1,   -1,   -1,   -1,   -1,   -1,   12,
+    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   15,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   16,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   17,   -1,   -1,
+    -1,   -1,   -1,   -1,   18,   -1,   -1,   17,
+    -1,   -1,   -1,   -1,   -1,   -1,   19,   -1,
+    -1,   20,   -1,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   -1,   20,   -1,   -1,   -1,   -1,
+    -1,   -1,   21,   -1,   -1,   20,   -1,   -1,
+    -1,   -1,   -1,   -1,   22,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    23,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    24,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   25,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   -1,   26,   27,
+    -1,   -1,   -1,   -1,   -1,   -1,   28,   -1,
+    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    29,   -1,   -1,   27,   -1,   30,   31,   -1,
+    -1,   -1,   32,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   -1,   30,   -1,
+    -1,   34,   30,   30,   -1,   -1,   -1,   -1,
+    30,   -1,   -1,   -1,   30,   30,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   27,   -1,   -1,
+    -1,   -1,   -1,   -1,   35,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   -1,   29,   -1,
+    -1,   34,   -1,   36,   37,   -1,   -1,   -1,
+    38,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   36,   -1,   -1,   39,   36,   36,
+    -1,   -1,   -1,   -1,   36,   -1,   -1,   -1,
+    36,   36,   -1,   -1,   40,   41,   -1,   -1,
+    -1,   38,   -1,   -1,   -1,   -1,   -1,   -1,
+    29,   -1,   -1,   39,   -1,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   40,   -1,   -1,   -1,   -1,   -1,
+    -1,   -1,   -1,   -1
+};
+
+int fromcheck_next_state(int current_state, int next_token) {
+  if (next_token < 0 || next_token >= 10) return -1;
+  return fromcheck_trans[10*current_state + next_token];
+}
