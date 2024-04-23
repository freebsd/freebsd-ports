commit a94cfcd734a0ac81cf157378b77732a3de6b9463
Author: Bryan Drewery <bryan@shatow.net>
Date:   Tue Apr 23 06:29:13 2024 -0700

    tests: Don't run git-log from 'make test' for Poudriere in ports
    
    This results in a very long lookup that returns nothing

--- test/common.sh.orig	2024-04-20 03:48:57 UTC
+++ test/common.sh
@@ -550,6 +550,7 @@ msg_debug "getpid: $$"
 
 msg_debug "getpid: $$"
 
-if git_get_hash_and_dirty "${abs_top_srcdir}" git_hash git_dirty; then
+if [ -r "${abs_top_srcdir}/.git" ] &&
+    git_get_hash_and_dirty "${abs_top_srcdir}" git_hash git_dirty; then
 	msg "Source git hash: ${git_hash} modified: ${git_dirty}"
 fi >&2
