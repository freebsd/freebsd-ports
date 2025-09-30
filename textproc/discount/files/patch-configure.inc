--- configure.inc.orig	2025-09-07 21:27:45 UTC
+++ configure.inc
@@ -1501,9 +1501,6 @@ EOF
 	$PROG_LN_S -f \$FULLNAME \$1/\$LIBNAME.\$MAJOR
 	$PROG_LN_S -f \$FULLNAME \$1/\$LIBNAME
 EOF
-    if [ "$LDCONFIG" -a -z "$CONTAINER" ]; then
-	echo '	'$LDCONFIG '"$1"' >> librarian.sh
-    fi
     
     cat >> librarian.sh << EOF
 	;;
