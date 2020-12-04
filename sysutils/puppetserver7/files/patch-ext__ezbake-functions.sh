--- ext/ezbake-functions.sh.orig	2019-09-17 14:05:56 UTC
+++ ext/ezbake-functions.sh
@@ -126,7 +126,7 @@ init_restart_file()
     local group="${GROUP:-puppet}"
 
     if [ ! -e "$restartfile" ]; then
-        /usr/bin/install --directory --owner=$user --group=$group --mode=755 "$restart_file_base_dir"
+        /usr/bin/install -d -o $user -g $group -m 755 "$restart_file_base_dir"
         if [ $? -ne 0 ]; then
             echo "Unable to create or set permissions for restart file at ${restart_file_base_dir}" 1>&2
             return 1
