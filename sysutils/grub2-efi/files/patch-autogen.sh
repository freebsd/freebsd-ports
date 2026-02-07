--- autogen.sh.orig	2015-06-03 14:54:01 UTC
+++ autogen.sh
@@ -83,5 +83,5 @@ echo "Running autoreconf..."
 echo timestamp > stamp-h.in
 
 echo "Running autoreconf..."
-autoreconf -vi
+autoreconf -vif
 exit 0
