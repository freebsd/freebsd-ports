diff -ruN admin/ltmain.sh admin/ltmain.sh
--- admin/ltmain.sh	Fri Apr 12 13:40:12 2002
+++ admin/ltmain.sh	Thu Jun 20 09:51:32 2002
@@ -1239,7 +1239,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd[0-4]*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
