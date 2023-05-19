--- tools/ccopts.sh.orig	2021-10-21 02:27:26 UTC
+++ tools/ccopts.sh
@@ -675,7 +675,7 @@ hasSafeStackLibs()
 
 if [ $ISCLANG -gt 0 ] && [ $ISSPECIAL -eq 0 ] ; then
 	if [ $COMPILER_VER -ge 47 ] ; then
-		if [ "$OSNAME" = "Darwin" ] || [ "$OSNAME" = "OpenBSD" ] ; then
+		if [ "$OSNAME" = "Darwin" ] || [ "$OSNAME" = "OpenBSD" ] || [ "$OSNAME" = "FreeBSD" -a "$ARCH" = "arm" ] || [ "$OSNAME" = "FreeBSD" -a "$ARCH" = "powerpc" ]; then
 			# The versions of clang shipped with OS X or OpenBSD don't
 			# support -fsanitize=safe-stack even as late as clang 12, so
 			# there's not much that we can do.
@@ -892,31 +892,6 @@ fi
 # a big deal.  As a convenient side-effect, this also enables the use of
 # ASLR where it's supported.
 
-if [ "$ARCH" = "i586" ] || [ "$ARCH" = "i686" ] || [ "$ARCH" = "x86_64" ] ; then
-	if [ "$COMPILER_VER" -ge 45 ] ; then
-		if [ $GENERICBUILD -gt 0 ] ; then
-			echo "  (Enabling lowest-common-denominator build options for cross-platform library)." >&2 ;
-		else
-			CCARGS="$CCARGS -march=native -mtune=generic" ;
-		fi
-		if [ "$ARCH" = "x86_64" ] ; then
-			CCARGS="$CCARGS -fPIC" ;
-		fi ;
-	elif [ "$COMPILER_VER" -ge 30 ] ; then
-		case $ARCH in
-			'x86_64')
-				CCARGS="$CCARGS -march=opteron -fPIC" ;;
-
-			'i686')
-				CCARGS="$CCARGS -march=pentiumpro" ;;
-
-			*)
-				CCARGS="$CCARGS -march=pentium" ;;
-		esac ;
-	else
-		CCARGS="$CCARGS -mcpu=pentium" ;
-	fi ;
-fi
 
 # gcc 4.x for 64-bit architectures has an optimiser bug that removes an
 # empty-list check in cryptlib's list-management code (this has been
