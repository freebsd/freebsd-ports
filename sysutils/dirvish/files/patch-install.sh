--- install.sh.orig	Fri Feb 18 16:56:13 2005
+++ install.sh	Thu Jun 16 14:17:32 2005
@@ -9,6 +9,8 @@ case `echo "testing\c"; echo 1,2,3`,`ech
   *)       ECHO_N= ECHO_C='\c' ECHO_T= ;;
 esac
 
+ECHO_N=
+
 EXECUTABLES="dirvish dirvish-runall dirvish-expire dirvish-locate"
 MANPAGES="dirvish.8 dirvish-runall.8 dirvish-expire.8 dirvish-locate.8"
 MANPAGES="$MANPAGES dirvish.conf.5"
@@ -29,6 +31,7 @@ do
 
 	until [ -n "$PREFIX_OK" ]
 	do
+		PREFIX="/usr/local"
 		EXECDIR="/usr/sbin"
 		CONFDIR="/etc/dirvish"
 		MANDIR="/usr/share/man"
@@ -61,9 +64,9 @@ do
 
 		if [ -d "$PREFIX/sbin" ]
 		then
-			BINDIR=$PREFIX/sbin
+			BINDIR="$PREFIX/sbin"
 		else
-			BINDIR=$PREFIX/bin
+			BINDIR="$PREFIX/bin"
 		fi
 
 		if [ -d "$PREFIX/share/man" ]
@@ -74,13 +77,16 @@ do
 			MANDIR=$PREFIX/usr/share/man
 		eli [ -d "$PREFIX/usr/man" ]
 		then
-			MANDIR="$PREFIX/usr/man" ]
+			MANDIR="$PREFIX/usr/man"
 		else
-			MANDIR=$PREFIX/man
+			MANDIR="$PREFIX/man"
 		fi
 		if [ `expr "$PREFIX" : '.*dirvish.*'` -gt 0 ]
 		then
 			CONFDIR="$PREFIX/etc"
+		elif [ -d "$PREFIX/etc" ]
+		then
+			CONFDIR="$PREFIX/etc/dirvish"
 		else
 			CONFDIR="/etc/dirvish"
 		fi
@@ -124,7 +130,7 @@ EOSTAT
 	if [ `expr "$ans" : '[qQ]'` -ne 0 ]
 	then
 		exit
-	elif [ `expr "$ans" : '[yY]'` -ne 0 ]
+	elif [ `expr "$ans" : '[nN]'` -eq 0 ]
 	then
 		break
 	fi
@@ -150,7 +156,7 @@ echo
 
 echo $ECHO_N "Install executables and manpages? (no/yes) $ECHO_C"
 read ans
-if [ `expr "$ans" : '[yY]'` -ne 0 ]
+if [ `expr "$ans" : '[nN]'` -eq 0 ]
 then
 	echo
 	if [ -n "$CREATE_PREFIX" ]
