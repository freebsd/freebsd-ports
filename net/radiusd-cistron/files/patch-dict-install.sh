--- src/dict-install.sh.orig	2003-04-10 16:17:11.000000000 +0200
+++ src/dict-install.sh	2013-12-01 06:23:00.000000000 +0100
@@ -31,7 +31,7 @@
 
 if [ $NEWTYPE = yes ]
 then
-	DESTDIR=$SHAREDIR
+	DESTDIR=$DESTROOT$SHAREDIR
 else
 	DESTDIR=$RADDBDIR
 fi
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
