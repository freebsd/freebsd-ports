--- ltmain.sh.orig	Thu Apr 28 17:56:47 2005
+++ ltmain.sh	Wed Jun  1 17:01:36 2005
@@ -1348,10 +1348,6 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd* | *-*-freebsd*)
-	    # Do not include libc due to us having libc/libc_r.
-	    test "X$arg" = "X-lc" && continue
-	    ;;
 	  *-*-rhapsody* | *-*-darwin1.[012])
 	    # Rhapsody C and math libraries are in the System framework
 	    deplibs="$deplibs -framework System"
