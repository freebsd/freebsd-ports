--- configure.sh.orig	2022-05-15 14:42:39 UTC
+++ configure.sh
@@ -183,7 +183,7 @@ fi
 
 [ x"$CC" = x ] && CC=gcc
 
-CFLAGS="-W -Wall"
+CFLAGS="$CFLAGS -W -Wall"
 if [ $debug = yes ]
 then
   CFLAGS="$CFLAGS -ggdb3"
@@ -194,7 +194,7 @@ else
   [ $lto = yes ] && CFLAGS="$CFLAGS -flto -fwhole-program"
 fi
 
-LIBS="-lm"
+LIBS="$LDFLAGS -lm"
 HDEPS=""
 LDEPS=""
 
