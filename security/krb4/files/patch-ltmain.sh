*** ltmain.sh.orig	Tue Oct 22 23:39:04 2002
--- ltmain.sh	Thu Feb 27 20:55:52 2003
***************
*** 4209,4220 ****
  	  IFS="$save_ifs"
  	fi
  
- 	# Install the pseudo-library for information purposes.
- 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
- 	instname="$dir/$name"i
- 	$show "$install_prog $instname $destdir/$name"
- 	$run eval "$install_prog $instname $destdir/$name" || exit $?
- 
  	# Maybe install the static library, too.
  	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
  	;;
--- 4209,4214 ----
