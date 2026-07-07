--- contrib/trainbogo.sh.orig	2025-04-04 13:02:33 UTC
+++ contrib/trainbogo.sh
@@ -178,7 +178,7 @@ if [ ! -f "${list}" ] || [ -n "${dofilelist}" ]; then
     for i in "${hamdir}"/* "${spamdir}"/*
       do
       [ ! -f "${i}" ] && continue
-      md5=$(printf "%s" "${rndseed}${i}" | md5sum | sed "s/  -//")
+      md5=$(printf "%s" "${rndseed}${i}" | md5)
       echo "${md5}  ${i}" >> "${list}"
     done
 
