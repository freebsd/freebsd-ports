--- src/typesize.sh.orig	2003-04-24 07:07:24 UTC
+++ src/typesize.sh
@@ -21,7 +21,7 @@ for i in "short" "int" "long " "unsigned
 	:
       else
 	x=$?
-	p=`echo $i | sed 's/ /_/g' | tr "[a-z]]" "[A-Z]"`
+	p=`echo $i | sed 's/ /_/g' | tr "[:lower:]" "[:upper:]"`
 	echo "#define SIZEOF_$p $x"
       fi
     fi
