--- src/typesize.sh.orig	2004-08-16 08:21:12.000000000 +0200
+++ src/typesize.sh	2009-11-27 15:50:42.000000000 +0100
@@ -21,7 +21,7 @@
 	:
       else
 	x=$?
-	p=`echo $i | sed 's/ /_/g' | tr "[a-z]]" "[A-Z]"`
+	p=`echo $i | sed 's/ /_/g' | tr "[:lower:]" "[:upper:]"`
 	echo "#define SIZEOF_$p $x /* systype-info */"
       fi
     fi
