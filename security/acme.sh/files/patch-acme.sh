diff --git acme.sh acme.sh
index 3316b25fa9..02986a332d 100755
--- acme.sh
+++ acme.sh
@@ -436,14 +436,28 @@ _secure_debug3() {
   fi
 }
 
+__USE_TR_TAG=""
+if [ "$(echo "abc" | LANG=C tr a-z A-Z 2>/dev/null)" != "ABC" ] ; then
+  __USE_TR_TAG="1"
+fi
+export __USE_TR_TAG
+
 _upper_case() {
+  if [ "$__USE_TR_TAG" ]; then
+    LANG=C tr '[:lower:]' '[:upper:]'
+  else
   # shellcheck disable=SC2018,SC2019
-  tr '[a-z]' '[A-Z]'
+    LANG=C tr '[a-z]' '[A-Z]'
+  fi
 }
 
 _lower_case() {
-  # shellcheck disable=SC2018,SC2019
-  tr '[A-Z]' '[a-z]'
+  if [ "$__USE_TR_TAG" ]; then
+    LANG=C tr '[:upper:]' '[:lower:]'
+  else
+    # shellcheck disable=SC2018,SC2019
+    LANG=C tr '[A-Z]' '[a-z]'
+  fi
 }
 
 _startswith() {
