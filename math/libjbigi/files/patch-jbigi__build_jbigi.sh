--- jbigi/build_jbigi.sh.orig	Fri Jan 21 18:52:41 2005
+++ jbigi/build_jbigi.sh	Fri Dec 23 11:13:55 2005
@@ -2,7 +2,6 @@
 # When executed in Mingw: Produces an jbigi.dll
 # When executed in Linux: Produces an libjbigi.so
 
-CC="gcc"
 
 case `uname -sr` in
 MINGW*)
@@ -24,9 +23,9 @@
         LINKFLAGS="-dynamiclib -framework JavaVM"
         LIBFILE="libjbigi.jnilib";;
 *)
-	COMPILEFLAGS="-fPIC -Wall"
-	INCLUDES="-I. -I../../jbigi/include -I$JAVA_HOME/include -I$JAVA_HOME/include/linux"
-	LINKFLAGS="-shared -Wl,-soname,libjbigi.so"
+	COMPILEFLAGS="-Wall ${CFLAGS}"
+	INCLUDES="-I. -I${LOCALBASE}/include -Ijbigi/include -I$JAVA_HOME/include -I$JAVA_HOME/include/freebsd"
+	LINKFLAGS="-shared -Wl,-soname,libjbigi.so ${LDFLAGS}"
 	LIBFILE="libjbigi.so";;
 esac
 
@@ -36,13 +35,13 @@
 then
 	echo "Building jbigi lib that is dynamically linked to GMP" 
 	LIBPATH="-L.libs"
-	INCLUDELIBS="-lgmp"
+	INCLUDELIBS="-L${LOCALBASE}/lib -lgmp"
 else
 	echo "Building jbigi lib that is statically linked to GMP"
-	STATICLIBS=".libs/libgmp.a"
+	STATICLIBS="${LOCALBASE}/lib/libgmp.a"
 fi
 
 echo "Compiling C code..."
 rm -f jbigi.o $LIBFILE
-$CC -c $COMPILEFLAGS $INCLUDES ../../jbigi/src/jbigi.c
+$CC -c $COMPILEFLAGS $INCLUDES jbigi/src/jbigi.c
 $CC $LINKFLAGS $INCLUDES $INCLUDELIBS -o $LIBFILE jbigi.o $STATICLIBS
