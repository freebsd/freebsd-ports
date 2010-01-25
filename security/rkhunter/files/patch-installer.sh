--- installer.sh.orig	2010-01-23 12:14:34.000000000 +0000
+++ installer.sh	2010-01-23 12:14:51.000000000 +0000
@@ -657,22 +657,7 @@
 		esac
 	done
 
-
-	# Application documents
-	for FILE in ${RKHINST_DOC_FILES}; do
-		cp -f ./files/"${FILE}" "${RKHINST_DOC_DIR}"
-		ERRCODE=$?
-
-		if [ $ERRCODE -eq 0 ]; then
-			echo " Installing ${FILE}: OK"
-			chmod "${RKHINST_MODE_RWR}" "${RKHINST_DOC_DIR}/${FILE}"
-		else
-			echo " Installing ${FILE}: FAILED: Code $ERRCODE: exiting."
-			exit 1
-		fi
-	done
-
-
+	
 	# Language support files
 	ERRCODE=0
 
