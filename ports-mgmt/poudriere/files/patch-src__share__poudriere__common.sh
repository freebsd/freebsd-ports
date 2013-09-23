--- ./src/share/poudriere/common.sh.orig	2013-09-23 10:17:57.011126466 -0500
+++ ./src/share/poudriere/common.sh	2013-09-23 10:18:06.769131620 -0500
@@ -588,10 +588,7 @@
 		zfs snapshot ${fs}@${name}
 	fi
 
-	if [ $domtree -eq 0 ]; then
-		echo " done"
-		return 0
-	fi
+	[ $domtree -eq 0 ] && return 0
 	mkdir -p ${mnt}/poudriere/
 
 	case "${name}" in
