--- examples/data/scripts/load_url_from_history.sh.orig	2011-10-06 03:31:31.000000000 +0100
+++ examples/data/scripts/load_url_from_history.sh	2011-10-06 03:32:32.000000000 +0100
@@ -15,7 +15,7 @@
 else
     # choose an item in reverse order, showing also the date and page titles
     # pick the last field from the first 3 fields. this way you can pick a url (prefixed with date & time) or type just a new url.
-    goto="$( tac "$UZBL_HISTORY_FILE" | $DMENU | cut -d ' ' -f -3  | awk '{ print $NF }' )"
+    goto="$( tail -r "$UZBL_HISTORY_FILE" | $DMENU | cut -d ' ' -f -3  | awk '{ print $NF }' )"
 fi
 
 [ -n "$goto" ] && echo "uri $goto" > "$UZBL_FIFO"
