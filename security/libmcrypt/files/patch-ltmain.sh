--- ltmain.sh.orig	Tue Nov 13 21:50:10 2001
+++ ltmain.sh	Sat Nov 24 22:47:52 2001
@@ -953,6 +953,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -1040,7 +1041,7 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd* )
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
@@ -1048,7 +1049,7 @@
 	 fi
 	 if test "X$arg" = "X-lc_r"; then
 	  case $host in
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd* )
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
@@ -2439,7 +2440,7 @@
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd* )
 	    # Do not include libc due to us having libc/libc_r.
 	    ;;
 	  *)
