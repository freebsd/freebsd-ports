--- test.sh.orig	2015-01-24 10:15:22 UTC
+++ test.sh
@@ -576,9 +576,6 @@ filloptionvalues() {
     *,dh,*) OPTS=$(echo "$OPTS" |sed "s/,dh,/,dh=/tmp/hugo,/g");;
     esac
     case "$OPTS" in
-    *,egd,*) OPTS=$(echo "$OPTS" |sed "s/,egd,/,egd=/tmp/hugo,/g");;
-    esac
-    case "$OPTS" in
     *,compress,*) OPTS=$(echo "$OPTS" |sed "s/,compress,/,compress=none,/g");;
     esac
     # PROXY
