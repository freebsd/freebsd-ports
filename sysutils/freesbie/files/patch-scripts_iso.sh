--- scripts/iso.sh.orig	2006-10-01 12:00:47 UTC
+++ scripts/iso.sh
@@ -48,7 +48,7 @@ cd ${CLONEDIR}
 
 echo "Running mkisofs..."
 
-mkisofs -b boot/cdboot -no-emul-boot -J -r -ldots -l -L -V ${FREESBIE_LABEL} -p FreeSBIE -o $ISOPATH . >> ${LOGFILE} 2>&1
+mkisofs -b boot/cdboot -no-emul-boot -J -r -ldots -l -allow-leading-dots -V ${FREESBIE_LABEL} -p FreeSBIE -o $ISOPATH . >> ${LOGFILE} 2>&1
 
 echo "ISO created:"
 
