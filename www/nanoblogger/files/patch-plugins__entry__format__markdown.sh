--- ./plugins/entry/format/markdown.sh.orig	2010-02-14 21:42:17.000000000 +0100
+++ ./plugins/entry/format/markdown.sh	2010-03-01 22:10:36.000000000 +0100
@@ -5,7 +5,7 @@
 : ${MARKDOWN_CMD:=markdown}
 : ${MARKDOWN_OPTS:= }
 
-nb_eval "$MARKDOWN_CMD" && MARKDOWN_INPATH=true
+nb_eval "$MARKDOWN_CMD -v" && MARKDOWN_INPATH=true
 	
 if [ "$MARKDOWN_INPATH" = "true" ]; then
 	# nb_msg "$plugins_entryfilteraction `basename $nb_plugin` ..."
