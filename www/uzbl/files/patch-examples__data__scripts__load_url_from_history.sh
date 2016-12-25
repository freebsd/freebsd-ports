--- examples/data/scripts/load_url_from_history.sh.orig	2016-10-29 15:00:34.816505000 +0200
+++ examples/data/scripts/load_url_from_history.sh	2016-10-29 15:01:01.835001000 +0200
@@ -17,7 +17,7 @@
     # cut: get the first three fields, awk: pick the last field
     # As opposed to just getting the third field directly, the combination of cut+awk allows
     # to enter a completely new URL (which would be field number 1 or $NF, but not 3).
-    goto="$( tac "$UZBL_HISTORY_FILE" | awk '!a[$3]++' | $DMENU | cut -d ' ' -f -3  | awk '{ print $NF }' )"
+    goto="$( tail -r "$UZBL_HISTORY_FILE" | awk '!a[$3]++' | $DMENU | cut -d ' ' -f -3  | awk '{ print $NF }' )"
 else
     readonly current="$( tail -n 1 "$UZBL_HISTORY_FILE" | cut -d ' ' -f 3 )"
     goto="$( ( print "$current\n"; cut -d ' ' -f 3 < "$UZBL_HISTORY_FILE" | grep -v -e "^$current\$" | sort -u ) | $DMENU )"
