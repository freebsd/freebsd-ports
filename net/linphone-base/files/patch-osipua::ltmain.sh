
$FreeBSD$

--- osipua/ltmain.sh.orig	Wed May 14 00:40:19 2003
+++ osipua/ltmain.sh	Sun Aug 17 19:30:25 2003
@@ -4325,10 +4325,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
