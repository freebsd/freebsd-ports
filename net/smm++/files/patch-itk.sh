--- ../../smm5r0/Install.unix/itk.sh	Mon Mar 19 08:46:07 2001
+++ itk.sh	Sun Jul 15 17:01:08 2001
@@ -1,32 +1,16 @@
 #!/bin/sh
 
 # all possible itkwish executables
-itkarray=(itkwish3.1 itkwish3 itkwish30 itkwish)
+itkarray="itkwish3.1 itkwish3 itkwish30 itkwish3.0 itkwish"
 
-# $PATH exploded as an array
-explode=(`echo $PATH | sed 's/:/ /g'`)
-
-element_count=${#explode[@]}
-i=0
-found=0
-while [ $i -lt ${element_count} ]
-do
-    second_count=${#itkarray[@]}
-    x=0
-    while [ $x -lt ${second_count} ]
-    do
-        if [ -x ${explode[$i]}/${itkarray[$x]} ]; then
-            smm=${explode[$i]}/${itkarray[$x]}
-	    found=1
-            break
-        fi
-        let "x=$x + 1"
-    done
-    let "i = $i + 1"
+set $itkarray
+while [ ! -z "$1" ]; do
+	smm=`which $1`
+	if [ $? -eq 0 ]; then
+		echo ${smm}
+		exit 0
+	fi
+	shift
 done
-if [ ${found} -eq 1 ] ; then
-    echo ${smm}
-    exit 0
-else
-    exit 1
-fi
+
+exit 1
