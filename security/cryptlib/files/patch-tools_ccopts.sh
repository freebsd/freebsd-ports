--- tools/ccopts.sh.orig	2021-10-21 02:27:26 UTC
+++ tools/ccopts.sh
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
