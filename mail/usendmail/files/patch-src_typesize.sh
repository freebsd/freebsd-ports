--- src/typesize.sh.orig	2009-11-22 19:02:59.000000000 +0100
+++ src/typesize.sh	2009-11-22 19:04:28.000000000 +0100
@@ -21,7 +21,7 @@
 	:
       else
 	x=$?
-	p=`echo $i | sed 's/ /_/g' | tr "[a-z]]" "[A-Z]"`
+	p=`echo $i | sed 's/ /_/g' | tr "[:lower:]" "[:upper:]"`
 	echo "#define SIZEOF_$p $x"
       fi
     fi
