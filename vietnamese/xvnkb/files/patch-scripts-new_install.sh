--- scripts/new_install.sh.orig	Fri Jan 16 23:19:17 2004
+++ scripts/new_install.sh	Wed Dec 29 15:28:22 2004
@@ -19,11 +19,11 @@
 #                                                                            #
 #----------------------------------------------------------------------------#
 
-PREFIX="/usr/local"
+#PREFIX="/usr/local"
 
 ID=`id -u`
-LD="/etc/ld.so.preload"
-SO="/lib/xvnkb.so"
+#LD="/etc/ld.so.preload"
+#SO="/lib/xvnkb.so"
 
 if [ "$ID" != "0" ]; then
 	echo "You must be root to install xvnkb."
@@ -46,56 +46,59 @@
 cp ./xvnkb $PREFIX/bin && echo ok
 echo -n "Copy xvnkb.so.$VERSION  =>  $PREFIX/lib ... "
 cp ./xvnkb.so.$VERSION $PREFIX/lib && echo ok
-echo -n "Copy xvnkb_localeconf.sh  =>  $PREFIX/bin ... "
-cp ./scripts/xvnkb.lconf.sh $PREFIX/bin/xvnkb_localeconf.sh && echo ok
-echo -n "Initialize xvnkb core ... "
-XVNKB_CORE="$SO.$VERSION"
-while [ -f $XVNKB_CORE ]; do
-	if [ "$N" = "" ]; then
-		N=1;
-	else
-		N=$((N + 1))
-	fi
-	XVNKB_CORE="$SO.$VERSION-$N"
-done
-cp ./xvnkb.so.$VERSION $XVNKB_CORE
-chattr +i $XVNKB_CORE
-if [ -f "$LD" ]; then
-	grep -v xvnkb.so $LD > $LD.xvnkb
-	/bin/mv -f $LD.xvnkb $LD
-fi
-echo "$XVNKB_CORE" >> $LD
-echo done
-
-if [ "$LANG" = "C" ]; then
-	LANG="en_US"
-fi
-
-if [ "`echo $LANG | grep UTF-8`" = "" ]; then
-	echo "If you want to input Vietnamese Unicode, please run"
-	echo
-	echo "  # $PREFIX/bin/xvnkb_localeconf.sh $LANG.UTF-8"
-	echo
-	echo "and set your LANG to $LANG.UTF-8."
-	echo "See xvnkb documents for more information."
-fi
-
-if [ "$OL" != "" ]; then
-	echo "You are using LD_PRELOAD to load xvnkb core."
-	echo "Try to remove this old setting style..."
-	if [ -f /etc/X11/xinit/xinitrc.d/xvnkb.sh ]; then
-		/bin/rm -f /etc/X11/xinit/xinitrc.d/xvnkb.sh
-	fi
-	echo -e "\\033[1;31m"
-	echo "* NOTICE: If you set it somewhere else (e.g. /etc/profile, /etc/bashrc,"
-	echo "~/.bash_profile, ~/.bashrc, ~/.xinitrc) by yourself, please remove it also!"
-	echo -e "\\033[0;39m"
-fi
+ln -sf $PREFIX/lib/xvnkb.so.$VERSION $PREFIX/lib/libxvnkb.so
+ln -sf $PREFIX/lib/xvnkb.so.$VERSION $PREFIX/lib/libxvnkb.so.0
 
-echo
-echo "You can use xvnkb now!  If you are using X, please restart your Window Manager."
-echo "It will load xvnkb core control automatically for you and affect to all"
-echo "applications.  Right now, xvnkb core control can affect to new starting"
-echo "applications only.  Run \"xvnkb\" to control status."
-echo
+#echo -n "Copy xvnkb_localeconf.sh  =>  $PREFIX/bin ... "
+#cp ./scripts/xvnkb.lconf.sh $PREFIX/bin/xvnkb_localeconf.sh && echo ok
+#echo -n "Initialize xvnkb core ... "
+#XVNKB_CORE="$SO.$VERSION"
+#while [ -f $XVNKB_CORE ]; do
+#	if [ "$N" = "" ]; then
+#		N=1;
+#	else
+#		N=$((N + 1))
+#	fi
+#	XVNKB_CORE="$SO.$VERSION-$N"
+#done
+#cp ./xvnkb.so.$VERSION $XVNKB_CORE
+#chattr +i $XVNKB_CORE
+#if [ -f "$LD" ]; then
+#	grep -v xvnkb.so $LD > $LD.xvnkb
+#	/bin/mv -f $LD.xvnkb $LD
+#fi
+#echo "$XVNKB_CORE" >> $LD
+#echo done
+
+#if [ "$LANG" = "C" ]; then
+#	LANG="en_US"
+#fi
+
+#if [ "`echo $LANG | grep UTF-8`" = "" ]; then
+#	echo "If you want to input Vietnamese Unicode, please run"
+#	echo
+#	echo "  # $PREFIX/bin/xvnkb_localeconf.sh $LANG.UTF-8"
+#	echo
+#	echo "and set your LANG to $LANG.UTF-8."
+#	echo "See xvnkb documents for more information."
+#fi
+
+#if [ "$OL" != "" ]; then
+#	echo "You are using LD_PRELOAD to load xvnkb core."
+#	echo "Try to remove this old setting style..."
+#	if [ -f /etc/X11/xinit/xinitrc.d/xvnkb.sh ]; then
+#		/bin/rm -f /etc/X11/xinit/xinitrc.d/xvnkb.sh
+#	fi
+#	echo -e "\\033[1;31m"
+#	echo "* NOTICE: If you set it somewhere else (e.g. /etc/profile, /etc/bashrc,"
+#	echo "~/.bash_profile, ~/.bashrc, ~/.xinitrc) by yourself, please remove it also!"
+#	echo -e "\\033[0;39m"
+#fi
+
+#echo
+#echo "You can use xvnkb now!  If you are using X, please restart your Window Manager."
+#echo "It will load xvnkb core control automatically for you and affect to all"
+#echo "applications.  Right now, xvnkb core control can affect to new starting"
+#echo "applications only.  Run \"xvnkb\" to control status."
+#echo
 
