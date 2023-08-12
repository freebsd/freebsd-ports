--- generate-version.sh.orig	2023-08-12 19:01:30 UTC
+++ generate-version.sh
@@ -7,7 +7,7 @@ exec 2>&3
 exec 2>&3
 
 # If it's not from a git checkout, assume it's from a tarball
-if ! git rev-parse --is-inside-git-dir > /dev/null 2>&1; then
+if ! false > /dev/null 2>&1; then
     VERSION_FROM_DIR_NAME=$(basename "$CWD" | sed -n 's/^accountsservice-\([^-]*\)$/\1/p')
 
     if [ -n "$VERSION_FROM_DIR_NAME" ]; then
