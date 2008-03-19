--- ./getdelta.sh.orig	2008-03-15 23:50:36.000000000 +0300
+++ ./getdelta.sh	2008-03-15 23:50:04.000000000 +0300
@@ -1,4 +1,4 @@
-#!/bin/sh
+#!%%LOCALBASE%%/bin/bash
 # getdelta.sh 
 # A download-wrapper script for gentoo that tries to get dtu files 
 # created by deltup instead of downloading complete source-files 
@@ -22,9 +22,35 @@
 #    59 Temple Place, Suite 330
 #    Boston, MA 02111, USA.
 
+
 VERSION="0.7"
 
+
 # Changelog
+# version 0.7.8-freebsd_4   	2008/03/15
+#		Anton Statutov:
+#		- version revision
+# version 0.7.8-freebsd_3   	2008/03/11
+#		Andrew R. Muhametshin:
+#		- fixed litte bug
+#		- fixed 'handled situation when required file already exists' - added the real check.
+# version 0.7.8-freebsd_2   	2008/03/11
+#		Andrew R. Muhametshin:
+#		- added refetch feature
+#		- added 'tgz' mask
+#		- added check of FETCH_CMD parameters
+# 		- distfiles path fixed
+#		- fixed 'date' calls
+#		- some work on CHECK_OLD_FILE
+#		Anton Statutov:
+#		- fixed litte ouput bug
+# version 0.7.8-freebsd_1   2008/02/12
+#		- handled situation when required file already exists in distfiles
+# version 0.7.8-freebsd   2008/02/09 by Anton Statutov stant@bestyle.ru
+#		- replaced "stat -c %s" to "stat -f "%z"
+#		- replaced "/etc/deltup" to "/usr/local/etc/deltup"
+#		- replaced $1 to $2 because $1 is the size of file on freebsd
+#		- some minor changes
 # version 0.7.8   2007/07/13
 #		- added option -O to call of emerge when finding mirrors
 #		- replaced some calls of coreutils with bash-internals
@@ -63,7 +89,7 @@
 #		  instead of asking the server - the server does not use this parameter - it just
 #		  exists to create unique request-URLS (as proposed by bodo "bothie" thiesen)
 # version 0.6.9	  2005/03/11
-#		­ exit with exitcode of wget to signal to portage if 
+#		- exit with exitcode of wget to signal to portage if
 #		  download was successful
 #		- handle metadata.dtd as exception (repoman uses FETCHCOMMAND)
 #		- you can disable fetching of dtu-files now by setting  
@@ -208,7 +234,9 @@
 # This file:                                       #
 ####################################################
 
-GETDELTA_CONFIGFILE=/etc/deltup/getdelta.rc
+PREFIX=%%PREFIX%%
+GETDELTA_CONFIGFILE="${PREFIX}/etc/deltup/getdelta.rc"
+DISTDIR=$(pwd)
 #
 
 splitversion(){
@@ -368,6 +396,7 @@
 	# ignore some strings in any filename
 	echo $(sed -e "s/\.bz2$//g" \
 		   -e "s/\.gz$//g" \
+		   -e "s/\.tgz$//g" \
 		   -e "s/[0-9]//g" \
 		   -e "s/pre//g" \
 		   -e "s/preview//g" \
@@ -378,18 +407,34 @@
 		   -e "s/ //g" <<< $MASK_FILENAME)
 }
 
+check_file(){
+	_return=0
+	_sfx1="$(rev <<< $1 | cut -d. -f1 | rev)"
+	_sfx2="$(rev <<< $1 | cut -d. -f2 | rev)"
+	if [ ${_sfx2} = "tar" -o ${_sfx1} = "tgz" -o ${_sfx1} = "tbz" ]
+	then
+		output "Testing file integrity with tar.\n"
+		if ! tar -tf $1 >/dev/null
+		then
+			output "${RED}reported an error while testing ${CYAN}$1${RED} - so this file is unusable.\n"
+			_return=1
+		fi
+	fi
+	return ${_return}
+}
+
 # create or update a config-file
 
 add_to_configfile KDE_MIRROR "ftp://ftp.kde.org/pub/kde/stable" "we de not get kde-deltas from a delta-up-server, since kde provides own xdelta-files"
 add_to_configfile LOCAL_MIRROR "" "set this to one or more (space separated) URI ending with '/' if you want to check one or more local mirror(s) first\n# most people just leave it empty."
 add_to_configfile DELTUP_SERVER "http://linux01.gwdg.de/~nlissne/deltup.php" "deltup-server to use"
-add_to_configfile FETCH "/usr/bin/wget -t 1 --passive-ftp" "command to use for downloading"
+add_to_configfile FETCH "${PREFIX}/bin/wget -t 1 --passive-ftp" "command to use for downloading"
 add_to_configfile QUEUERETRY 15 "number of seconds to wait before a queued request is retried"
 add_to_configfile MAXIMUM_ACCEPTABLE_QUEUEPOS "15" "the maximum queuepos you would accept (if higher download full archive instead)"
 add_to_configfile QUEUETIMEOUT 900 "when a dtu-request is queued - how long should we wait max. before downloading the original archive instead (in seconds)"
 add_to_configfile CHECK_OLD_FILE "false" "set to \"true\", if you want getdelta.sh to use Pkunk's integrity check for the old file before downloading dtu-files"
 add_to_configfile REMOVE_OLD "false" "set to \"true\", if you want getdelta.sh to delete the old file, if patch was succesful"
-add_to_configfile DO_NOT_REMOVE "/etc/deltup/do_not_remove" "a list of files not to be removed by REMOVE_OLD feature"
+add_to_configfile DO_NOT_REMOVE "${PREFIX}/etc/deltup/do_not_remove" "a list of files not to be removed by REMOVE_OLD feature"
 add_to_configfile REMOVE_INCOMPLETE_OLD_FILES "false" "set this to \"true\" if you want getdelta.sh to delete old versions that seems to be corrupt,\n# or to \"false\" if you want to delete them manually\n# note: getdelta.sh will not use these files anyway"
 add_to_configfile VERBOSITY true "set to \"true\", if you want verbose outputs (later to be set to a level [0-3])"
 add_to_configfile COLOR true "set to \"true\", if you want colorful messages, \"false\" if not."
@@ -424,23 +469,6 @@
 add_to_donotremove "^rp-pppoe"
 
 
-if [ -z $1 ]
-then
-	COLOR=true
-	echo -e "${YELLOW}getdelta.sh version ${VERSION}"
-	echo "This script has to be called like this:"
-	echo -e "${CYAN}$0 <URI>"
-	echo -e "\n${YELLOW}To use it, you should just put the following line into your /etc/make.conf"
-	echo -e "${GREEN}FETCHCOMMAND=\"$0 \\\${URI}\""
-	echo -e "\n${YELLOW}There is a config-file ${CYAN}${GETDELTA_CONFIGFILE}${YELLOW} with some variables to control the behaviour of this script."
-	echo -e "Edit it to your needs.${NORMAL}"
-	exit 1
-fi 
-# include variables from gentoo make.globals and make.conf
-source /etc/make.globals
-source /etc/make.conf
-
-
 if ${COLOR} 
 then
 	RED="\033[01;31m"
@@ -459,14 +487,32 @@
 	CYAN=""
 	NORMAL=""
 fi
+
 grep -q "getdelta.sh" <<< "${RESUMECOMMAND}" && 
 	output "${RED}do NOT set RESUMECOMMAND to use getdelta.sh" && 
 	output "use getdelta.sh for your FETCHCOMMAND, only." &&
 	sleep 5 && exit 1
 
-pushd $DISTDIR >/dev/null 2>/dev/null
-ORIG_URI=$1
+
+if [[ "${1%%-S*}" ]] ; then ORIG_URI=$1 ; else ORIG_URI=$2 ; fi
 NEW_FILE=$(basename $ORIG_URI)
+TMP_DWN_FILE="${DISTDIR}/.download_tmp-$NEW_FILE"
+
+
+if [ -z "${ORIG_URI}" -a -z "${NEW_FILE}" ]
+then
+	COLOR=true
+	echo -e "${YELLOW}getdelta.sh version ${VERSION}"
+	echo "This script has to be called like this:"
+	echo -e "${CYAN}$0 <URI>"
+	echo -e "\n${YELLOW}To use it, you should just put the following line into your /etc/make.conf"
+	echo -e "${GREEN}FETCH_CMD=\"$0\""
+	echo -e "\n${YELLOW}There is a config-file ${CYAN}${GETDELTA_CONFIGFILE}${YELLOW} with some variables to control the behaviour of this script."
+	echo -e "Edit it to your needs.${NORMAL}"
+	exit 1
+fi
+
+pushd $DISTDIR >/dev/null 2>/dev/null
 
 # repoman downloads metadata.dtd with FETCHCOMMAND
 # this should not be done with getdelta - so just fetch the file and exit
@@ -578,7 +624,12 @@
 if ! [ -z "$filelist" ] 
 then 
 	# we have got a list of candidates in $filelist now. find the best match .
-	output "${GREEN}We have the following candidates to choose from \n${YELLOW}`sed -e \"s/\ /\\n/g\" <<< $filelist` \n"
+	output "${GREEN}We have the following candidates to choose from:"
+	for _name in $filelist
+	do
+		output "${YELLOW}${_name}"
+	done
+	output ""
 
 	# find matching part of filename - first: frontmatch
 	x=0;
@@ -588,7 +639,7 @@
 	do
 		for ((i=0;i<${#a[@]};i++))
 		do
-			[ ${a[0]:${x}:1} != ${a[$i]:${x}:1} ] &&  match=$x
+			[[ ${a[0]:${x}:1} != ${a[$i]:${x}:1} ]] &&  match=$x
 		done
 		((x++))
 	done
@@ -601,7 +652,7 @@
 	do
 		for ((i=0;i<${#a[@]};i++))
 		do
-			[ ${a[0]:${#a[0]}-${x}:1} != ${a[$i]:${#a[$i]}-${x}:1} ] &&  match=$x
+			[[ ${a[0]:${#a[0]}-${x}:1} != ${a[$i]:${#a[$i]}-${x}:1} ]] &&  match=$x
 		done
 		((x++))
 	done
@@ -652,31 +703,23 @@
 	output "${GREEN}The best of all is ... ${CYAN}${best_candidate}\n"
 	output "${YELLOW}Checking if this file is OK.\n"
 	
-	# this part is based on Pkunk's code posted on http://bugs.gentoo.org/show_bug.cgi?id=63525
-	# but with some changes
 	FILE_IS_CORRUPT=false
-	if $CHECK_OLD_FILE 
-	then
-		file_digest=$(grep -h ${best_candidate} ${FILESDIR}/digest-* | sed -n 1p)
-		if [ "$file_digest" ]
+
+	if [ "${best_candidate}" = "${NEW_FILE}" ]
 		then
-			file_md5=$(cut -d ' ' -f2 <<< "$file_digest") 
-			file_origsize=$(cut -d ' ' -f4 <<< "$file_digest")
-			file_currentsize=$(stat -c %s ${best_candidate})
-			if [ $file_currentsize -ne $file_origsize ]
+		output "${RED}Required file already exists... \n"
+		if ! check_file "${best_candidate}"
 			then
-				output "${RED}Found ${best_candidate}, but filesize ${CYAN}${file_currentsize} ${RED} does not match ${CYAN}${file_origsize} (found in digest-file)\n"
-				FILE_IS_CORRUPT=true
-			fi
+			exit 1
 		else
-			if [ $(rev <<< ${best_candidate} | cut -d. -f2 | rev) = "tar" ]
-			then
-				output "${YELLOW}Could not find a digest-file for ${CYAN}${best_candidate}${YELLOW}. Testing file integrity with tar.\n"
-				if ! tar -tf ${best_candidate} >/dev/null
-				then
-					output "${RED}reported an error while testing ${CYAN}${best_candidate}${RED} - so this file is unusable.\n"
-					FILE_IS_CORRUPT=true
+			output "${RED}md5 checksum is not correct ${CYAN}\"$DISTDIR/${best_candidate}\"${RED} - but this file is usable.\n"
+			exit 0
 				fi
+	fi
+
+	if $CHECK_OLD_FILE
+	then
+		check_file "${best_candidate}" || FILE_IS_CORRUPT=true
 			
 				if $FILE_IS_CORRUPT && $REMOVE_INCOMPLETE_OLD_FILES
 				then
@@ -684,27 +727,24 @@
 					remove ${best_candidate}
 				fi
 			fi
-		fi
-	fi
+
 	# end of file-corruption check for $best_candidate found in distfiles
 	if ! $FILE_IS_CORRUPT
 	then
 		
-		QUERY_URL=$(GENTOO_MIRRORS="" emerge -fOp =${CATEGORY}/${PF} 2>&1 | 
-			    sed -e "s/ /\\n/g" | egrep "(http|ftp)://" | 
-			    grep "${NEW_FILE}" | tail -n 1)
+		QUERY_URL=${ORIG_URI}
 		query="?have=${best_candidate}&want=${NEW_FILE}&url=${QUERY_URL}&version=${VERSION}&time=$(date +%s)"
 		output "${GREEN}Trying to download ${YELLOW}${best_candidate}-${NEW_FILE}.dtu\n"
 
 		# Remember where we are, and go to a new dir there we can work
-		tmp_dwn_dest="${DISTDIR}/.getdelta-`date +%N`-tmp"
+		tmp_dwn_dest="${DISTDIR}/.getdelta-`date +%s`_${RANDOM}-tmp"
 		mkdir ${tmp_dwn_dest}
 		# If user abort Ctrl+C (signal 2), remove tmp-dir; enabable trap again and send it again to stop wget
 		trap "rm -r ${tmp_dwn_dest}; trap 2; kill -2 $$" 2
 		pushd ${tmp_dwn_dest} >/dev/null 2>&1
 
 		# thanks to MATSUI Fe2+ Tetsushi for idea and patch
-		FILESIZE=$(stat -c %s "${DISTDIR}/${best_candidate}")
+		FILESIZE=$(stat -f "%z" "${DISTDIR}/${best_candidate}")
 		let TIMELIMIT=${FILESIZE}/${BANDWIDTH}
 		[[ $TIMELIMIT -lt $QUEUETIMEOUT ]] && QUEUETIMEOUT=$TIMELIMIT
 			
@@ -771,10 +811,10 @@
 			if [ -f ${best_candidate}-${NEW_FILE}.dtu ]
 			then
 				output "${GREEN}Successfully fetched the dtu-file - let's build ${NEW_FILE}...\n" 
-				downloadsize=$(stat -c %s  ${best_candidate}-${NEW_FILE}.dtu)
+				downloadsize=$(stat -f "%z"  ${best_candidate}-${NEW_FILE}.dtu)
 				if deltup -p -v -D ${DISTDIR} ${best_candidate}-${NEW_FILE}.dtu 
 				then 
-					newsize=$(stat -c %s ${NEW_FILE})
+					newsize=$(stat -f "%z" ${NEW_FILE})
 					let savedsize=${newsize}-${downloadsize}
 					let percent=${savedsize}*100/${newsize}
 					unit="bytes"
@@ -824,12 +864,22 @@
 	
 # Ok, once we are here, we should have got the delta (and used it)
 # or we still have to download the full file
+
 if ! [ -f ${DISTDIR}/${NEW_FILE} ] 
 then
 	output "${RED}The dtu could not be fetched,${YELLOW} downloading full file from original URL\n"
-	$FETCH $ORIG_URI
+
+	$FETCH -O "${TMP_DWN_FILE}" -c "$ORIG_URI"
+
 # remember we had a fallback to use correct exitcode for portage
 	FALLBACK=$?
+
+	if [ $FALLBACK = 0 ] ; then
+		output "${YELOW}Download complete\n"
+		mv "${TMP_DWN_FILE}" "${DISTDIR}/${NEW_FILE}"
+	fi
+else
+		[ -f "${TMP_DWN_FILE}" ] && rm "${TMP_DWN_FILE}"
 fi
 
 
