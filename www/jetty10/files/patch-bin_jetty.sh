--- bin/jetty.sh.orig	2024-07-04 13:34:53 UTC
+++ bin/jetty.sh
@@ -313,7 +313,7 @@ then
   ETC=$HOME/etc
 fi
 
-for CONFIG in {/etc,~/etc}/default/${NAME}{,9} $HOME/.${NAME}rc; do
+for CONFIG in {/etc,~/etc}/default/${NAME}{,9} /usr/local/etc/${NAME}/${NAME}{,9} $HOME/.${NAME}rc; do
   if [ -f "$CONFIG" ] ; then
     readConfig "$CONFIG"
   fi
