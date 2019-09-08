--- locate/updatedb.sh.orig	2019-06-23 09:00:40 UTC
+++ locate/updatedb.sh
@@ -292,7 +292,7 @@ cd "$changeto"
 if test -n "$SEARCHPATHS"; then
   if [ "$LOCALUSER" != "" ]; then
     # : A1
-    su $LOCALUSER `select_shell $LOCALUSER` -c \
+    su -m $LOCALUSER -c \
     "$find $SEARCHPATHS $FINDOPTIONS \
      \\( $prunefs_exp \
      -type d -regex '$PRUNEREGEX' \\) -prune -o $print_option"
@@ -308,7 +308,7 @@ if test -n "$NETPATHS"; then
 myuid=`getuid`
 if [ "$myuid" = 0 ]; then
     # : A3
-    su $NETUSER `select_shell $NETUSER` -c \
+    su -m $NETUSER -c \
      "$find $NETPATHS $FINDOPTIONS \\( -type d -regex '$PRUNEREGEX' -prune \\) -o $print_option" ||
     exit $?
   else
