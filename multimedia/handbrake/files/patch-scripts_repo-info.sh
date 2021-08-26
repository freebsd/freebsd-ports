--- scripts/repo-info.sh.orig	2021-08-15 11:58:50 UTC
+++ scripts/repo-info.sh
@@ -1,7 +1,7 @@
 #!/usr/bin/env bash
 #
 # Retrieves git repository info for directory ${1} using command ${2}
-
+exit 1
 function repo_info()
 {
     local repo_dir git_exe commit upstream err
