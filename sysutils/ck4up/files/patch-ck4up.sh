--- ck4up.sh.orig	Sun Nov 19 21:39:51 2006
+++ ck4up.sh	Sun Nov 19 21:40:12 2006
@@ -5,7 +5,7 @@
 #
 # Jürgen Daubert <juergen.daubert@t-online.de>
 
-PROG='/usr/bin/ck4up'
+PROG='%%PREFIX%%/bin/ck4up'
 DIFF=`$PROG $@ | awk '{if ($3 ~ /diff:/) {print $4} else {print $0 > "/dev/stderr"}}'`
 TEST_MOZ=`ps ax | grep -v grep | grep -c firefox`
 
