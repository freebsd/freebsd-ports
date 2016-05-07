--- examples/data/scripts/load_url_from_history.sh.orig	2016-02-28 14:27:33 UTC
+++ examples/data/scripts/load_url_from_history.sh
@@ -13,7 +13,7 @@
 if $DMENU_HAS_VERTICAL; then
     # choose an item in reverse order, showing also the date and page titles
     # pick the last field from the first 3 fields. this way you can pick a url (prefixed with date & time) or type just a new url.
-    goto="$( tac "$UZBL_HISTORY_FILE" | $DMENU | cut -d ' ' -f -3  | awk '{ print $NF }' )"
+    goto="$( tail -r "$UZBL_HISTORY_FILE" | $DMENU | cut -d ' ' -f -3  | awk '{ print $NF }' )"
 else
     readonly current="$( tail -n 1 "$UZBL_HISTORY_FILE" | cut -d ' ' -f 3 )"
     goto="$( ( print "$current\n"; cut -d ' ' -f 3 < "$UZBL_HISTORY_FILE" | grep -v -e "^$current\$" | sort -u ) | $DMENU )"
