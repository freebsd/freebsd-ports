--- BashBurn.sh.orig	2007-07-18 21:48:55.000000000 +0200
+++ BashBurn.sh	2007-08-24 14:58:30.000000000 +0200
@@ -31,18 +31,13 @@
 # This is run at first
 init_bashburn()
 {
-	if [[ -r "${BBCONFFILE}" ]]; then	# If /etc/bashburnrc exists, read in the vars.
+	if [[ ! -r "${BBCONFFILE}" ]]; then
+		cp ${BBCONFFILE}.sample ${BBCONFFILE}
+	fi
 		export BBROOTDIR="$( cat $BBCONFFILE | grep -v '^#' | grep BBROOTDIR:  | cut -d ":" -f 2- | sed -e "s/^[[:blank:]]//g")"
 		source ${BBROOTDIR}/misc/commands.idx
 		source ${BBROOTDIR}/misc/variables.idx
 		export BBTEMPMOUNTDIR="${BBBURNDIR}/mnt"
-	else
-		echo "There is no '${BBCONFFILE}'" 1>&2		
-		echo "That is the file where BashBurn stores its settings."
-		echo "You must run the BashBurn installation script first as root to install"
-		echo "all needed files. Do that now and then start 'bashburn' again."
-		exit 1
-	fi
 	
 	# Read in the language file
 	source ${BBROOTDIR}/lang/${BBLANG}/BashBurn.lang
