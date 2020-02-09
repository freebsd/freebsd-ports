--- scripts/builtin_documentation.sh.orig	2019-08-30 05:32:36.000000000 -0700
+++ scripts/builtin_documentation.sh	2019-08-30 12:40:24.125856000 -0700
@@ -8,6 +8,6 @@
     cmd_name=$(basename "$in_file" .1)
     [ "$cmd_name" = ksh ] && continue
     echo "const char sh_opt${cmd_name}[] ="
-    sed -e 's/\(.*\)/    "\1\\n"/' < "$in_file"
+    sed -e 's/"//g;s/\(.*\)/    "\1\\n"/' < "$in_file"
     echo ";"
 done
