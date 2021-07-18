--- configure.inc.orig	2020-08-24 05:45:49 UTC
+++ configure.inc
@@ -1501,7 +1501,6 @@ install)$PROG_INSTALL -c \$FULLNAME "\$1"
 	$PROG_LN_S -f \$FULLNAME \$1/\$LIBNAME.\$MAJOR
 	$PROG_LN_S -f \$FULLNAME \$1/\$LIBNAME
 EOF
-    test "$LDCONFIG" && echo '	'$LDCONFIG '"$1"' >> librarian.sh
     cat >> librarian.sh << EOF
 	;;
 esac
