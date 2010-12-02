--- ./installer.sh.orig	2010-11-16 22:34:48.000000000 +0100
+++ ./installer.sh	2010-11-27 02:40:03.000000000 +0100
@@ -366,10 +366,10 @@
 	else
 		RKHINST_DB_DIR="${VARDIR}/lib/${APPNAME}/db"
 		RKHINST_TMP_DIR="${VARDIR}/lib/${APPNAME}/tmp"
-		RKHINST_DOC_DIR="${SHAREDIR}/doc/${APPNAME}-${APPVERSION}"
+		RKHINST_DOC_DIR="${SHAREDIR}/doc/${APPNAME}"
 	fi
 
-	RKHINST_MAN_DIR="${SHAREDIR}/man/man8"
+	RKHINST_MAN_DIR="${PREFIX}/man/man8"
 	RKHINST_LANG_DIR="${RKHINST_DB_DIR}/i18n"
 
 	RKHINST_ETC_FILE="${APPNAME}.conf"
@@ -765,22 +765,6 @@
 		esac
 	done
 
-
-	# Application documents
-	for FILE in ${RKHINST_DOC_FILES}; do
-		cp -f ./files/"${FILE}" "${RKHINST_DOC_DIR}" >/dev/null 2>&1
-		ERRCODE=$?
-
-		if [ $ERRCODE -eq 0 ]; then
-			echo " Installing ${FILE}: OK"
-			chmod "${RKHINST_MODE_RWR}" "${RKHINST_DOC_DIR}/${FILE}"
-		else
-			echo " Installing ${FILE}: FAILED: Code $ERRCODE"
-			exit 1
-		fi
-	done
-
-
 	# Language support files
 	ERRCODE=0
 
