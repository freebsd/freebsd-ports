--- BashBurn.sh.orig	2007-11-09 19:02:46.000000000 +0100
+++ BashBurn.sh	2008-01-17 23:17:18.000000000 +0100
@@ -31,7 +31,11 @@
 # This is run at first
 init_bashburn()
 {
-	if [[ -r "${BBCONFFILE}" ]]; then	# If /etc/bashburnrc exists, read in the vars.
+ 	if [[ ! -f "${BBCONFFILE}" ]]; then
+ 		cp ${BBCONFFILE}.sample ${BBCONFFILE}
+ 	fi
+
+ 	if [[ -r "${BBCONFFILE}" ]]; then
 		# Next line a tip from paddor
 		export BBROOTDIR="$( sed -n 's/^[[:blank:]]*BBROOTDIR:[[:blank:]]*\(.*\)/\1/p' < $BBCONFFILE)"
 		source ${BBROOTDIR}/misc/commands.idx
