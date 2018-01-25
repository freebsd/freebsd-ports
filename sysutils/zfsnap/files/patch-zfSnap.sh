--- zfSnap.sh.orig	2013-01-18 03:37:09.000000000 +0700
+++ zfSnap.sh	2018-01-22 23:20:20.257104000 +0700
@@ -199,6 +199,8 @@ rm_zfs_snapshot() {
 }
 
 skip_pool() {
+    local i
+
     # more like skip pool???
     if is_true $scrub_skip; then
         for i in $scrub_pools; do
