--- ./src/poudriere.d/common.sh.orig	2012-07-04 12:38:06.000000000 +0200
+++ ./src/poudriere.d/common.sh	2012-07-24 10:58:57.289711665 +0200
@@ -610,7 +610,7 @@
 	local pn
 	msg "Caching missing port versions"
 	while read port; do
-		if ! egrep -q "^${port} " ${cache}; then
+		if ! grep -q "^${port} " ${cache}; then
 			pn=$(injail make -C /usr/ports/${port} -VPKGNAME)
 			echo "${port} ${pn}" >> ${cache}
 		fi
@@ -635,7 +635,7 @@
 	export LOCALBASE=${MYBASE:-/usr/local}
 	while read p; do
 		pn=$(awk -v o=${p} ' { if ($1 == o) {print $2} }' ${cache})
-		[ ! -f ${PKGDIR}/All/${pn}.${EXT} ] && queue="${queue} $p"
+		[ ! -f "${PKGDIR}/All/${pn}.${EXT}" ] && queue="${queue} $p"
 	done < ${tmplist2}
 
 	rm -f ${tmplist2} ${deplist} ${tmplist}
