--- jetty_bastillion/bin/jetty.sh.orig	2019-08-13 19:07:08 UTC
+++ jetty_bastillion/bin/jetty.sh
@@ -17,7 +17,8 @@
 # Set the name which is used by other variables.
 # Defaults to the file name without extension.
 ##################################################
-NAME=$(echo $(basename $0) | sed -e 's/^[SK][0-9]*//' -e 's/\.sh$//')
+#NAME=$(echo $(basename $0) | sed -e 's/^[SK][0-9]*//' -e 's/\.sh$//')
+NAME=bastillion
 
 # To get the service to restart correctly on reboot, uncomment below (3 lines):
 # ========================
@@ -199,7 +200,7 @@ then
   ETC=$HOME/etc
 fi
 
-for CONFIG in {/etc,~/etc}/default/${NAME}{,9} $HOME/.${NAME}rc; do
+for CONFIG in {/etc,~/etc}/default/${NAME}{,9} $HOME/.${NAME}rc /usr/local/etc/${NAME}/${NAME}{,9}; do
   if [ -f "$CONFIG" ] ; then
     readConfig "$CONFIG"
   fi
