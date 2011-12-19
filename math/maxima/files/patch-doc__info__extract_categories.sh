--- doc/info/extract_categories.sh.orig	2011-08-01 00:39:51.000000000 -0400
+++ doc/info/extract_categories.sh	2011-12-16 09:05:05.000000000 -0500
@@ -17,9 +17,10 @@
   if [ $f = "maxima.texi" ]
     then echo SKIP OVER $f
     else
-      sed 's/^@def\(fn\|vr\)  *{[^}]*}  *\([^[:blank:]]*\).*/@anchor{Item: \2}\
-\0/; s/^@node  *\([^,]*\).*/@anchor{Item: \1}\
-\0/' "$f" > tmp.texi
+      sed 's/^@deffn  *{[^}]*}  *\([^[:blank:]]*\).*/@anchor{Item: \1}\
+&/; s/^@defvr  *{[^}]*}  *\([^[:blank:]]*\).*/@anchor{Item: \1}\
+&/; s/^@node  *\([^,]*\).*/@anchor{Item: \1}\
+&/' "$f" > tmp.texi
       mv tmp.texi "$f"
     fi
 done
