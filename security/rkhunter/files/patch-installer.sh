--- installer.sh.orig	2018-02-19 23:49:06 UTC
+++ installer.sh
@@ -393,7 +393,7 @@ selectTemplate() { # Take input from the "--install pa
 	RKHINST_ETC_DIR="${SYSCONFIGDIR}"
 	RKHINST_BIN_DIR="${BINDIR}"
 	RKHINST_SCRIPT_DIR="${LIBDIR}/${APPNAME}/scripts"
-	RKHINST_MAN_DIR="${SHAREDIR}/man/man8"
+	RKHINST_MAN_DIR="${PREFIX}/share/man/man8"
 
 	if [ "${RKHINST_LAYOUT}" = "oldschool" ]; then
 		RKHINST_DB_DIR="${VARDIR}/${APPNAME}/db"
@@ -407,12 +407,12 @@ selectTemplate() { # Take input from the "--install pa
 	elif [ "${RKHINST_LAYOUT}" = "TXZ" ]; then
 		RKHINST_DB_DIR="${VARDIR}/lib/${APPNAME}/db"
 		RKHINST_TMP_DIR="${VARDIR}/lib/${APPNAME}/tmp"
-		RKHINST_DOC_DIR="${PREFIX}/doc/${APPNAME}-${APPVERSION}"
+		RKHINST_DOC_DIR="${PREFIX}/doc/${APPNAME}"
 		RKHINST_MAN_DIR="${PREFIX}/man/man8"
 	else
 		RKHINST_DB_DIR="${VARDIR}/lib/${APPNAME}/db"
 		RKHINST_TMP_DIR="${VARDIR}/lib/${APPNAME}/tmp"
-		RKHINST_DOC_DIR="${SHAREDIR}/doc/${APPNAME}-${APPVERSION}"
+		RKHINST_DOC_DIR="${SHAREDIR}/doc/${APPNAME}"
 	fi
 
 	RKHINST_LANG_DIR="${RKHINST_DB_DIR}/i18n"
@@ -1070,22 +1070,6 @@ doRemove()  {
 			fi
 		fi
 	done
-
-
-	# Application
-	for FILE in ${RKHINST_BIN_FILES}; do
-		if [ -f "${RKHINST_BIN_DIR}/${FILE}" ]; then
-			rm -f "${RKHINST_BIN_DIR}/${FILE}" >/dev/null 2>&1
-			ERRCODE=$?
-
-			if [ $ERRCODE -eq 0 ]; then
-				echo " Removing ${RKHINST_BIN_DIR}/${FILE}: OK"
-			else
-				echo " Removing ${RKHINST_BIN_DIR}/${FILE}: FAILED: Code $ERRCODE"
-			fi
-		fi
-	done
-
 
 	# Configuration file
 	for FILE in ${RKHINST_ETC_FILE}; do
