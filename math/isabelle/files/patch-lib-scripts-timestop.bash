--- lib/scripts/timestop.bash.orig	Fri Dec  2 04:44:47 2005
+++ lib/scripts/timestop.bash	Sat Jan 12 17:54:13 2008
@@ -7,28 +7,29 @@
 
 TIMES_REPORT=""
 
-function show_times ()
+show_times ()
 {
-  local TIMES_START="$TIMES_RESULT"
+  local TIMES_START TIMES_STOP KIND START STOP TIME SECS MINUTES HOURS \
+	KIND_NAME RESULT
+
+  TIMES_START="$TIMES_RESULT"
   get_times
-  local TIMES_STOP="$TIMES_RESULT"
-  local KIND
+  TIMES_STOP="$TIMES_RESULT"
   for KIND in 1 2
   do
-    local START=$(echo "$TIMES_START" | cut -d " " -f $KIND)
-    local STOP=$(echo "$TIMES_STOP" | cut -d " " -f $KIND)
+    START=$(echo "$TIMES_START" | cut -d " " -f $KIND)
+    STOP=$(echo "$TIMES_STOP" | cut -d " " -f $KIND)
 
-    local TIME=$[ $STOP - $START ]
-    local SECS=$[ $TIME % 60 ]
+    TIME=$(( $STOP - $START ))
+    SECS=$(( $TIME % 60 ))
     [ $SECS -lt 10 ] && SECS="0$SECS"
-    local MINUTES=$[ ($TIME / 60) % 60 ]
+    MINUTES=$(( ($TIME / 60) % 60 ))
     [ $MINUTES -lt 10 ] && MINUTES="0$MINUTES"
-    local HOURS=$[ $TIME / 3600 ]
+    HOURS=$(( $TIME / 3600 ))
 
-    local KIND_NAME
     [ "$KIND" = 1 ] && KIND_NAME="elapsed time"
     [ "$KIND" = 2 ] && KIND_NAME="cpu time"
-    local RESULT="${HOURS}:${MINUTES}:${SECS} ${KIND_NAME}"
+    RESULT="${HOURS}:${MINUTES}:${SECS} ${KIND_NAME}"
 
     if [ -z "$TIMES_REPORT" ]; then
       TIMES_REPORT="$RESULT"
