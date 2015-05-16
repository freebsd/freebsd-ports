--- sendmail/Makefile.m4.orig	2014-11-11 15:49:49 UTC
+++ sendmail/Makefile.m4
@@ -13,8 +13,7 @@ bldPUSH_SMLIB(`smutil')
 
 
 dnl hack: /etc/mail is not defined as "location of .cf" in the build system
-define(`bldTARGET_INST_DEP', ifdef(`confINST_DEP', `confINST_DEP',
-`${DESTDIR}/etc/mail/submit.cf ${DESTDIR}${MSPQ}'))dnl
+define(`bldTARGET_INST_DEP', ifdef(`confINST_DEP', `confINST_DEP'))
 define(`bldTARGET_LINKS', ifdef(`confLINKS', `confLINKS',
 `${DESTDIR}${UBINDIR}/newaliases ${DESTDIR}${UBINDIR}/mailq ${DESTDIR}${UBINDIR}/hoststat ${DESTDIR}${UBINDIR}/purgestat')
 )dnl
