--- tools/fix_file_permissions.sh.orig	2019-01-03 16:11:17 UTC
+++ tools/fix_file_permissions.sh
@@ -6,7 +6,7 @@
 # servers, the "world" permissions should be removed, and the corresponding changes made to
 # the configuration variables listed below.
 
-OPT=-c              # -c: Show changes.   On FreeBSD,  needs to be -vv
+OPT=-vv             # -c: Show changes.   On FreeBSD,  needs to be -vv
 
 ROOT=444            # Server root read only
 DIR=755             # Directories need "exec" for directory operations. Matches {Store}{dirPermission}
