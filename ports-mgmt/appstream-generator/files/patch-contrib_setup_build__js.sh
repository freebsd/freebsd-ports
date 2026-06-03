--- contrib/setup/build_js.sh.orig	2026-02-10 19:57:51 UTC
+++ contrib/setup/build_js.sh
@@ -17,10 +17,10 @@ JS_TARGET=../../data/templates/default/static/js
 [ ! -d "$JS_TARGET" ] && mkdir $JS_TARGET
 
 [ ! -d "$JS_TARGET/jquery" ] && mkdir $JS_TARGET/jquery
-install node_modules/jquery/dist/*.min.js -t $JS_TARGET/jquery
+install node_modules/jquery/dist/*.min.js $JS_TARGET/jquery
 
 [ ! -d "$JS_TARGET/flot" ] && mkdir $JS_TARGET/flot
-install node_modules/jquery-flot/jquery.flot*.js -t $JS_TARGET/flot
+install node_modules/jquery-flot/jquery.flot*.js $JS_TARGET/flot
 
 [ ! -d "$JS_TARGET/highlight" ] && mkdir $JS_TARGET/highlight
-install node_modules/highlightjs/*.js -t $JS_TARGET/highlight
+install node_modules/highlightjs/*.js $JS_TARGET/highlight
