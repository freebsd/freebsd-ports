--- scripts/iso.sh.orig	2006-10-01 14:00:47.000000000 +0200
+++ scripts/iso.sh	2011-11-06 18:07:26.544790101 +0100
@@ -48,7 +48,7 @@
 
 echo "Running mkisofs..."
 
-mkisofs -b boot/cdboot -no-emul-boot -J -r -ldots -l -L -V ${FREESBIE_LABEL} -p FreeSBIE -o $ISOPATH . >> ${LOGFILE} 2>&1
+mkisofs -b boot/cdboot -no-emul-boot -J -r -ldots -l -allow-leading-dots -V ${FREESBIE_LABEL} -p FreeSBIE -o $ISOPATH . >> ${LOGFILE} 2>&1
 
 echo "ISO created:"
 
