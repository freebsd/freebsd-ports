--- lib/SDLAudio/ltmain.sh.orig	Sun Nov  7 21:50:06 2004
+++ lib/SDLAudio/ltmain.sh	Sun Nov  7 21:50:28 2004
@@ -5425,10 +5425,12 @@
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
