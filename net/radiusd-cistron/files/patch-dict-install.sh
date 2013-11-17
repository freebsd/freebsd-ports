--- src/dict-install.sh.orig	2003-04-10 16:17:11.000000000 +0200
+++ src/dict-install.sh	2013-11-17 09:11:22.000000000 +0100
@@ -41,9 +41,9 @@
 	mkdir -p $DESTDIR
 fi
 
-if [ $NEWTYPE ] && [ ! -f $RADDBDIR/dictionary ]
+if [ $NEWTYPE ] && [ ! -f $DESTROOT$RADDBDIR/dictionary ]
 then
-	sed -e "s!SHAREDIR!$SHAREDIR!" < dictionary > $RADDBDIR/dictionary
+	sed -e "s!SHAREDIR!$SHAREDIR!" < dictionary > $DESTROOT$RADDBDIR/dictionary
 fi
 
 echo "Creating/updating dictionary files in $DESTDIR"
