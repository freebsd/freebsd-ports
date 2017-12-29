--- join-duplicates.sh.orig	2011-04-10 13:17:26 UTC
+++ join-duplicates.sh
@@ -25,16 +25,19 @@ duff -r '-f#' -z -p -P "$1" |
       if [ "$first" == '' ]; then
         first="$file"
       else
-	temp=`mktemp -p \`dirname $file\``
+	dir=`dirname "$file"`
+	temp=`gmktemp -p "$dir"`
 
 	mv "$file" "$temp" && \
 	ln "$first" "$file" && \
-	touch --reference="$temp" "$file" && \
+	gtouch --reference="$temp" "$file" && \
 	rm "$temp"
 
+	echo "$first <- $file"
+
 	if [ $? != 0 ]; then
-	  echo "`basename $0`: $file: failed to join with $first"
-	  echo "`basename $0`: $file: may exist as $temp"
+	  echo "`basename "$0"`: $file: failed to join with $first"
+	  echo "`basename "$0"`: $file: may exist as $temp"
 	  exit 1
 	fi
       fi
