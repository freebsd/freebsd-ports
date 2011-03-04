--- tools/ccopts.sh.orig	2010-12-19 00:57:12.000000000 +0100
+++ tools/ccopts.sh	2011-03-04 15:33:54.000000000 +0100
@@ -341,22 +341,6 @@ fi
 # in situations that also use shared libs, in the case of x86-64 the use
 # of PIC should have minimum overhead so it shouldn't be a big deal.
 
-if [ "$ARCH" = "i586" -o "$ARCH" = "i686" -o "$ARCH" = "x86_64" ] ; then
-	if [ "$GCC_VER" -ge 30 ] ; then
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
