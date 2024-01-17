--- bin/jetty.sh.orig	2024-01-15 19:55:56 UTC
+++ bin/jetty.sh
@@ -313,7 +313,7 @@ then
   ETC=$HOME/etc
 fi
 
-for CONFIG in {/etc,~/etc}/default/${NAME}{,9} $HOME/.${NAME}rc; do
+for CONFIG in {/etc,~/etc}/default/${NAME}{,9} $HOME/.${NAME}rc /usr/local/etc/${NAME}/${NAME}{,9}; do
   if [ -f "$CONFIG" ] ; then
     readConfig "$CONFIG"
   fi
@@ -459,7 +459,7 @@ then
   (( DEBUG )) && echo "$JETTY_CONF: (begin read) JETTY_ARGS.length=${#JETTY_ARGS[@]}"
   while read -r CONF
   do
-    if expr "$CONF" : '#' >/dev/null ; then
+    if expr -- "$CONF" : '#' >/dev/null ; then
       continue
     fi
 
