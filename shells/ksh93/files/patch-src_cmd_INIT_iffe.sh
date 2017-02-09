--- src/cmd/INIT/iffe.sh.orig	2013-03-06 16:33:17 UTC
+++ src/cmd/INIT/iffe.sh
@@ -3414,7 +3414,7 @@ $src
 						(eval "$src") <&$nullin || e=1
 						;;
 					mac*|nomac*)
-						if	compile $cc -E $tmp.c <&$nullin >$tmp.i
+						if	compile $cc -E -P $tmp.c <&$nullin >$tmp.i
 						then	sed -e '/<<[ 	]*".*"[ 	]*>>/!d' -e 's/<<[ 	]*"//g' -e 's/"[ 	]*>>//g' $tmp.i
 						else	e=1
 						fi
@@ -3705,7 +3705,7 @@ $inc
 <<\"#define $v\">>	$v	<<\"/* native $v */\">>
 <<\"#endif\">>
 #endif" > $tmp.c
-					if	compile $cc -E $tmp.c <&$nullin >$tmp.i
+					if	compile $cc -E -P $tmp.c <&$nullin >$tmp.i
 					then	sed -e '/<<[ 	]*".*"[ 	]*>>/!d' -e 's/<<[ 	]*"//g' -e 's/"[ 	]*>>//g' $tmp.i > $tmp.t
 						if	test -s $tmp.t
 						then	success
