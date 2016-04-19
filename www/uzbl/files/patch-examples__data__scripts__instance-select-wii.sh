--- examples/data/scripts/instance-select-wmii.sh.orig	2016-03-23 07:35:11 UTC
+++ examples/data/scripts/instance-select-wmii.sh
@@ -40,7 +40,7 @@ case "$action" in
     ;;
 "prev")
     readonly current="$( wmiir read /client/sel/ctl | head -n 1 )"
-    readonly prev="$( wmiir read /tag/sel/index | grep -B 10000 " $current " | tac | grep -m 1 uzbl | cut -d ' ' -f 2 )"
+    readonly prev="$( wmiir read /tag/sel/index | grep -B 10000 " $current " | tail -r | grep -m 1 uzbl | cut -d ' ' -f 2 )"
     if [ -n "$prev" ]; then
         wmiir xwrite /tag/sel/ctl "select client $prev"
     fi
