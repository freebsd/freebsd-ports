--- makegen/library_unix.mm.orig	Fri Aug 22 03:49:39 2003
+++ makegen/library_unix.mm	Tue Oct 28 12:45:32 2003
@@ -8,14 +8,6 @@ then
 fi
 
 
-if echo '\c' | grep -s c >/dev/null 2>&1
-then
-	ECHO_N="echo -n"
-	ECHO_C=""
-else
-	ECHO_N="echo"
-	ECHO_C='\c'
-fi
 
 
 lib=$1
@@ -24,10 +16,6 @@ libobj=`echo $3 | sed "s/,/ /g"`
 
 for src in $libsrc
 do
-	if test -c /dev/tty
-	then
-		$ECHO_N ".$ECHO_C" > /dev/tty
-	fi
 	base=`echo $src | sed "s/\..*//"`
 	obj=`echo $src | sed "s/\.c\$/.o/"`
 	libobj="$libobj $obj"
