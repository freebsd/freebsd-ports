--- ./contrib/trainbogo.sh.orig	2007-07-24 00:44:06.000000000 +0200
+++ ./contrib/trainbogo.sh	2011-08-31 12:15:20.000000000 +0200
@@ -181,7 +181,7 @@
     for i in "${hamdir}"/* "${spamdir}"/*
       do
       [ ! -f "${i}" ] && continue
-      md5=$(printf "%s" "${rndseed}${i}" | md5sum | sed "s/  -//")
+      md5=$(printf "%s" "${rndseed}${i}" | md5)
       echo "${md5}  ${i}" >> "${list}"
     done
 
