--- installer.sh.orig	Wed Oct 17 13:38:52 2007
+++ installer.sh	Wed Oct 17 13:40:59 2007
@@ -399,7 +399,7 @@
 
 # Perl will be found in Rkhunter itself.
 
-RKHINST_DIRS="$RKHINST_DOC_DIR $RKHINST_MAN_DIR $RKHINST_ETC_DIR $RKHINST_BIN_DIR"
+RKHINST_DIRS="$RKHINST_ETC_DIR $RKHINST_BIN_DIR"
 RKHINST_DIRS_EXCEP="$RKHINST_SCRIPT_DIR $RKHINST_DB_DIR $RKHINST_TMP_DIR $RKHINST_LANG_DIR"
 
 echo "Starting installation/update"
@@ -526,11 +526,11 @@
 done
 
 # Application documents
-for FILE in ${RKHINST_DOC_FILES}; do
-	echo $N " Installing ${FILE}: "
-	cp -f ./files/"${FILE}" "${RKHINST_DOC_DIR}"; retValChk
-	chmod "${RKHINST_MODE_RWR}" "${RKHINST_DOC_DIR}/${FILE}"
-done
+#for FILE in ${RKHINST_DOC_FILES}; do
+#	echo $N " Installing ${FILE}: "
+#	cp -f ./files/"${FILE}" "${RKHINST_DOC_DIR}"; retValChk
+#	chmod "${RKHINST_MODE_RWR}" "${RKHINST_DOC_DIR}/${FILE}"
+#done
 
 # Language support files
 echo $N " Installing language support files: "
