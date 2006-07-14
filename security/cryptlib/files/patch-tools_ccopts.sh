--- tools/ccopts.sh.orig	Fri Jul 14 08:37:59 2006
+++ tools/ccopts.sh	Fri Jul 14 08:38:19 2006
@@ -129,13 +129,6 @@
 # "version gcc" (we can't use just "gcc" by itself since this appears
 # elsewhere in the gcc -v output).
 
-if [ `uname -m | grep "i[3,4,5,6]86"` > /dev/null ] ; then
-	if [ `gcc --version 2>&1 | head -n 1 | tr -d '[A-Za-z]. ()' | cut -c 1` -gt 2 ] ; then
-		CCARGS="$CCARGS -march=pentium" ;
-	else
-		CCARGS="$CCARGS -mcpu=pentium" ;
-	fi
-fi
 
 # Check for gcc 4.x with its stupid default setting of -Wpointer-sign,
 # which leads to endless warnings about signed vs.unsigned char problems -
