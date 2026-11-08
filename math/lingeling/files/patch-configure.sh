-- Honor CFLAGS/LDFLAGS from the environment/port framework instead of
-- hardcoding them, and use "|" instead of "," as the sed delimiter when
-- generating the makefile so that CFLAGS/LDFLAGS values containing commas
-- (e.g. "-Wl,--fix-cortex-a53-843419") do not break the substitution.

--- configure.sh.orig	2024-03-05 09:03:23 UTC
+++ configure.sh
@@ -183,7 +183,7 @@ fi
 
 [ x"$CC" = x ] && CC=gcc
 
-CFLAGS="-W -Wall"
+CFLAGS="$CFLAGS -W -Wall"
 if [ $debug = yes ]
 then
   CFLAGS="$CFLAGS -ggdb3"
@@ -194,7 +194,7 @@ fi
   [ $lto = yes ] && CFLAGS="$CFLAGS -flto -fwhole-program"
 fi
 
-LIBS="-lm"
+LIBS="$LDFLAGS -lm"
 HDEPS=""
 LDEPS=""
 
@@ -270,12 +270,12 @@ sed \
 
 rm -f makefile
 sed \
-  -e "s,@CC@,$CC," \
-  -e "s,@CFLAGS@,$CFLAGS," \
-  -e "s,@HDEPS@,$HDEPS," \
-  -e "s,@LDEPS@,$LDEPS," \
-  -e "s,@EXTRAOBJS@,$EXTRAOBJS," \
-  -e "s,@AIGERTARGETS@,$AIGERTARGETS," \
-  -e "s,@AIGER@,$AIGER," \
-  -e "s,@LIBS@,$LIBS," \
+  -e "s|@CC@|$CC|" \
+  -e "s|@CFLAGS@|$CFLAGS|" \
+  -e "s|@HDEPS@|$HDEPS|" \
+  -e "s|@LDEPS@|$LDEPS|" \
+  -e "s|@EXTRAOBJS@|$EXTRAOBJS|" \
+  -e "s|@AIGERTARGETS@|$AIGERTARGETS|" \
+  -e "s|@AIGER@|$AIGER|" \
+  -e "s|@LIBS@|$LIBS|" \
   makefile.in > makefile
