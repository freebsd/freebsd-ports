--- scripts/pkginstall.sh.orig	2007-01-16 10:14:46 UTC
+++ scripts/pkginstall.sh
@@ -52,7 +52,7 @@ find_origins() {
 
 	# pkg_info might fail if the listed package isn't present
 	set +e
-	origins=$(pkg_info -EX "^$(escape_pkg ${pkg})($|-[^-]+$)")
+	origins=$(pkg query -x "%n-%v" "^$(escape_pkg ${pkg})($|-[^-]+$)")
 	retval=$?
 	set -e
 	if [ ${retval} -eq 0 ]; then
@@ -84,7 +84,7 @@ find_deps() {
     touch deps
     echo -n "Finding dependencies... "
     while read pkg; do
-	deps=$(pkg_info -qr ${pkg} | cut -d ' ' -f 2)
+	deps=$(pkg query "%dn-%dv" ${pkg})
 	for dep in ${deps}; do
 	    echo ${dep} >> tmp_deps
 	done      
@@ -142,7 +142,7 @@ copy_packages() {
     export PACKAGE_BUILDING=yo
     chrootpkgpath=${CHROOTWD#$BASEDIR}
     pkgfile=${WORKDIR}/sortpkg
-    pkgaddcmd="chroot ${BASEDIR} pkg_add -v"
+    pkgaddcmd="/usr/local/sbin/pkg -c ${BASEDIR} add -f "
     totpkg=$(wc -l $pkgfile | awk '{print $1}')
     echo "Copying ${totpkg} packages"
     cd ${CHROOTWD}
@@ -159,7 +159,11 @@ copy_packages() {
 	count=$((${count} + 1))
 
 	echo "Running pkg_create -b ${pkg} ${CHROOTWD}/${pkg}.tar" >> ${LOGFILE}
-	pkg_create -b ${pkg} ${CHROOTWD}/${pkg}.tar >> ${LOGFILE} 2>&1
+	rpkg=`pkg query %dn-%dv ${pkg}` 
+	for spkg in ${rpkg}; do
+		pkg create -o ${CHROOTWD} -n -f tar ${spkg} >> ${LOGFILE} 2>&1
+	done
+	pkg create -o ${CHROOTWD} -n -f tar ${pkg} >> ${LOGFILE} 2>&1
 
 	echo "Running $pkgaddcmd ${chrootpkgpath}/${pkg}.tar" >> ${LOGFILE}
 	$pkgaddcmd ${chrootpkgpath}/${pkg}.tar >> ${LOGFILE} 2>&1
@@ -168,12 +172,17 @@ copy_packages() {
 
     done < $pkgfile
     echo "]"
+    if [ -f ${WORKDIR}/extra/customroot/var/db ]; then
+	chroot ${BASEDIR} pkg backup -d test.db
+	env PKG_DBDIR=${WORKDIR}extra/customroot/var/db/pkg pkg backup -r ${BASEDIR}/test.db
+	rm ${BASEDIR}/test.db
+    fi
     set -e
 }
 
 delete_old_packages() {
     echo "Deleting previously installed packages"
-    chroot ${BASEDIR} pkg_delete -a >> ${LOGFILE} 2>&1
+    pkg -c ${BASEDIR} delete -afy >> ${LOGFILE} 2>&1
 }
 
 # Deletes workdirs
