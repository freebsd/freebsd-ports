--- ./ltmain.sh.orig	2011-12-02 07:35:01.000000000 -0500
+++ ./ltmain.sh	2011-12-02 07:35:23.000000000 -0500
@@ -8051,7 +8051,7 @@
 	    elif test -n "$runpath_var"; then
 	      case "$perm_rpath " in
 	      *" $libdir "*) ;;
-	      *) func_apped perm_rpath " $libdir" ;;
+	      *) func_append perm_rpath " $libdir" ;;
 	      esac
 	    fi
 	  done
