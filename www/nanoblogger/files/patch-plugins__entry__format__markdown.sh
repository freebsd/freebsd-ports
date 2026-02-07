--- ./plugins/entry/format/markdown.sh	2010-02-14 21:42:17.000000000 +0100
+++ ./plugins/entry/format/markdown.sh	2011-07-01 21:31:22.000000000 +0200
@@ -5,7 +5,7 @@
 : ${MARKDOWN_CMD:=markdown}
 : ${MARKDOWN_OPTS:= }
 
-nb_eval "$MARKDOWN_CMD" && MARKDOWN_INPATH=true
+nb_eval "$MARKDOWN_CMD -v" && MARKDOWN_INPATH=true
 	
 if [ "$MARKDOWN_INPATH" = "true" ]; then
 	# nb_msg "$plugins_entryfilteraction `basename $nb_plugin` ..."
