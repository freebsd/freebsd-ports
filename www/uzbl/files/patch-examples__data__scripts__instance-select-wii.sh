--- examples/data/scripts/instance-select-wmii.sh.orig	2011-10-06 03:29:31.000000000 +0100
+++ examples/data/scripts/instance-select-wmii.sh	2011-10-06 03:30:05.000000000 +0100
@@ -35,7 +35,7 @@
         ;;
     "prev")
         current="$( wmiir read /client/sel/ctl | head -n 1 )"
-        prev="$( wmiir read /tag/sel/index | grep -B 10000 " $current " | tac | grep -m 1 uzbl | cut -d ' ' -f 2 )"
+        prev="$( wmiir read /tag/sel/index | grep -B 10000 " $current " | tail -r | grep -m 1 uzbl | cut -d ' ' -f 2 )"
         if [ -n "$prev" ]; then
             wmiir xwrite /tag/sel/ctl "select client $prev"
         fi
