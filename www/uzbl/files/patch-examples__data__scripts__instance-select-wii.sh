--- examples/data/scripts/instance-select-wmii.sh.orig	2016-10-29 14:53:48.987875000 +0200
+++ examples/data/scripts/instance-select-wmii.sh	2016-10-29 14:54:09.084640000 +0200
@@ -40,7 +40,7 @@
     ;;
 "prev")
     readonly current="$( wmiir read /client/sel/ctl | head -n 1 )"
-    readonly prev="$( wmiir read /tag/sel/index | grep -B 10000 " $current " | tac | grep -m 1 uzbl | cut -d ' ' -f 2 )"
+    readonly prev="$( wmiir read /tag/sel/index | grep -B 10000 " $current " | tail -r | grep -m 1 uzbl | cut -d ' ' -f 2 )"
     if [ -n "$prev" ]; then
         wmiir xwrite /tag/sel/ctl "select client $prev"
     fi
