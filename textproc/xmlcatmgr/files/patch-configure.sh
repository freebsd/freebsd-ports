--- configure.sh.orig	Tue Dec 23 11:27:37 2003
+++ configure.sh	Mon Jan 12 17:37:47 2004
@@ -462,16 +462,18 @@
 install: all
 EOF
 
-install_dir ${DIR_DOC} >> ${mkfile}
 install_dir ${DIR_EXEC} >> ${mkfile}
 install_dir ${DIR_MAN}/man1 >> ${mkfile}
 install_program xmlcatmgr ${DIR_EXEC}/xmlcatmgr >> ${mkfile}
 install_data xmlcatmgr.1 ${DIR_MAN}/man1/xmlcatmgr.1 >> ${mkfile}
+if [ ! ${NOPORTDOCS} ]; then
+install_dir ${DIR_DOC} >> ${mkfile}
 install_data ${TOPDIR}/CHANGES ${DIR_DOC}/CHANGES >> ${mkfile}
 install_data ${TOPDIR}/COPYING ${DIR_DOC}/COPYING >> ${mkfile}
 install_data ${TOPDIR}/PEOPLE ${DIR_DOC}/PEOPLE >> ${mkfile}
 install_data ${TOPDIR}/README ${DIR_DOC}/README >> ${mkfile}
 install_data ${TOPDIR}/TODO ${DIR_DOC}/TODO >> ${mkfile}
+fi
 
 echo "# End of generated Makefile." >> ${mkfile}
 
