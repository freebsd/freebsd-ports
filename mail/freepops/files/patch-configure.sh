--- configure.sh.orig	Wed Jan  5 17:13:08 2005
+++ configure.sh	Sat Mar  5 21:29:33 2005
@@ -23,7 +23,7 @@
 }
 
 set_default() {
-CC=gcc
+#CC=gcc
 LD=ld
 AR=ar
 STRIP=strip
@@ -36,7 +36,7 @@
 EXEEXTENSION=
 STATICEXTENSION=.a
 SHAREDEXTENSION=.so
-CFLAGS="-O2 -g3 -Wall -DHAVE_CONFIG_H -I$PWD"
+CFLAGS="$CFLAGS -Wall -DHAVE_CONFIG_H -I$PWD"
 HCFLAGS=$CFLAGS
 LDFLAGS=""
 HLDFLAGS=$LDFLAGS
