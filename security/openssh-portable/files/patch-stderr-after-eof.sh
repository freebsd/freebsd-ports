--- regress/stderr-after-eof.sh.orig	Wed May  1 05:17:35 2002
+++ regress/stderr-after-eof.sh	Fri Jul 19 07:22:18 2002
@@ -7,7 +7,7 @@
 DATA=${OBJ}/data
 COPY=${OBJ}/copy
 
-MD5=md5sum
+MD5=md5
 
 # setup data
 rm -f ${DATA} ${COPY}
