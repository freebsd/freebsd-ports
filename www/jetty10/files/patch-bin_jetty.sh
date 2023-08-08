--- bin/jetty.sh.orig	2016-03-19 21:43:53 UTC
+++ bin/jetty.sh
@@ -166,7 +166,7 @@ then
   ETC=$HOME/etc
 fi
 
-for CONFIG in {/etc,~/etc}/default/${NAME}{,9} $HOME/.${NAME}rc; do
+for CONFIG in {/etc,~/etc}/default/${NAME}{,9} $HOME/.${NAME}rc /usr/local/etc/${NAME}/${NAME}{,9}; do
   if [ -f "$CONFIG" ] ; then
     readConfig "$CONFIG"
   fi
