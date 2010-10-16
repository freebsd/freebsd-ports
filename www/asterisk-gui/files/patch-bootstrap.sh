--- bootstrap.sh.orig	Wed Aug  1 18:59:07 2007
+++ bootstrap.sh	Wed Aug  1 19:00:28 2007
@@ -14,8 +14,8 @@
 
 uname -s | grep -q FreeBSD
 if [ $? = 0 ] ; then	# FreeBSD case
-	MY_AC_VER=259
-	MY_AM_VER=19
+	MY_AC_VER=-2.68
+	MY_AM_VER=-1.11
 else	# linux case
 	MY_AC_VER=
 	MY_AM_VER=
