--- src/gen.preload.conf.sh.orig	2014-04-11 10:21:23.519354010 -0400
+++ src/gen.preload.conf.sh	2014-04-11 10:21:32.509354646 -0400
@@ -4,6 +4,6 @@
 KEYS="$2"
 
 I='[ \t]*\([^, \t]*\)[ \t]*'
-SEDSCRIPT=`sed -e "s/confkey($I,$I,$I,$I,$I)/s@default_\3@\4@g; s@unit_\3@\5@g;/;" < "$KEYS"`
+SEDSCRIPT=`gsed -e "s/confkey($I,$I,$I,$I,$I)/s@default_\3@\4@g; s@unit_\3@\5@g;/;" < "$KEYS"`
 
-sed -e "$SEDSCRIPT" "$IN"
+gsed -e "$SEDSCRIPT" "$IN"
