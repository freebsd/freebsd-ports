--- ./plugins/calendar.sh	2011-07-01 21:31:36.000000000 +0200
+++ ./plugins/calendar.sh	2011-07-01 21:32:12.000000000 +0200
@@ -12,6 +12,7 @@
 cal_month="$2"
 cal_file="$3"
 : ${CAL_CMD:=cal}
+: ${CAL_ARGS:=-h}
 mkdir -p `dirname "$cal_file"`
 # halt if cal command fails
 nb_eval "$CAL_CMD" || continue
