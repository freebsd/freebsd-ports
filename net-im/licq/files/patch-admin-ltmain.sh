--- admin/ltmain.sh.orig	Sun Oct 26 04:47:29 2003
+++ admin/ltmain.sh	Sun Oct 26 04:47:56 2003
@@ -1239,7 +1239,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;

