--- ltmain.sh.orig	Tue Nov 30 15:55:46 2004
+++ ltmain.sh	Tue Nov 30 15:55:59 2004
@@ -561,7 +561,6 @@
 	    # Evaluate the configuration.
 	    eval "`${SED} -n -e '/^# ### BEGIN LIBTOOL TAG CONFIG: '$z'$/,/^# ### END LIBTOOL TAG CONFIG: '$z'$/p' < $0`"
 	    # user sometimes does CC=<HOST>-gcc so we need to match that to 'gcc'
-	    trimedcc="${CC/${host}-}"
 	    case "$base_compile " in
 	    "gcc "* | " gcc "* | "${host}-gcc "* | " ${host}-gcc "*)
 	    tagname=CC
@@ -954,7 +953,6 @@
 	    # Evaluate the configuration.
 	    eval "`${SED} -n -e '/^# ### BEGIN LIBTOOL TAG CONFIG: '$z'$/,/^# ### END LIBTOOL TAG CONFIG: '$z'$/p' < $0`"
 	    # user sometimes does CC=<HOST>-gcc so we need to match that to 'gcc'
-	    trimedcc="${CC/${host}-}"
 	    case $base_compile in
 	    "gcc "* | " gcc "* | "${host}-gcc "* | " ${host}-gcc "*)
 	    tagname=CC
