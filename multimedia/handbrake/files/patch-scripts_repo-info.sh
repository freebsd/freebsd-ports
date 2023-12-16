--- scripts/repo-info.sh.orig	2023-11-12 12:42:45 UTC
+++ scripts/repo-info.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 #
 # Retrieves git repository info for directory ${1} using command ${2}
-
+exit 1
 repo_info()
 {
     # Process args
