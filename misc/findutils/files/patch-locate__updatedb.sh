--- locate/updatedb.sh.orig	2011-04-03 23:53:12.000000000 +0100
+++ locate/updatedb.sh	2011-05-17 18:20:29.000000000 +0100
@@ -250,7 +250,7 @@
 if test -n "$SEARCHPATHS"; then
   if [ "$LOCALUSER" != "" ]; then
     # : A1
-    su $LOCALUSER `select_shell $LOCALUSER` -c \
+    su -m $LOCALUSER -c \
     "$find $SEARCHPATHS $FINDOPTIONS \
      \\( $prunefs_exp \
      -type d -regex '$PRUNEREGEX' \\) -prune -o $print_option"
@@ -266,7 +266,7 @@
 myuid=`getuid`
 if [ "$myuid" = 0 ]; then
     # : A3
-    su $NETUSER `select_shell $NETUSER` -c \
+    su -m $NETUSER -c \
      "$find $NETPATHS $FINDOPTIONS \\( -type d -regex '$PRUNEREGEX' -prune \\) -o $print_option" ||
     exit $?
   else
@@ -319,7 +319,7 @@
 if test -n "$SEARCHPATHS"; then
   if [ "$LOCALUSER" != "" ]; then
     # : A5
-    su $LOCALUSER `select_shell $LOCALUSER` -c \
+    su -m $LOCALUSER -c \
     "$find $SEARCHPATHS $FINDOPTIONS \
      \( $prunefs_exp \
      -type d -regex '$PRUNEREGEX' \) -prune -o $print_option" || exit $?
@@ -335,7 +335,7 @@
   myuid=`getuid`
   if [ "$myuid" = 0 ]; then
     # : A7
-    su $NETUSER `select_shell $NETUSER` -c \
+    su -m $NETUSER -c \
      "$find $NETPATHS $FINDOPTIONS \\( -type d -regex '$PRUNEREGEX' -prune \\) -o $print_option" ||
     exit $?
   else
