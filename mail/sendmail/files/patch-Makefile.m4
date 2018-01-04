--- sendmail/Makefile.m4.orig	2015-06-19 12:59:29 UTC
+++ sendmail/Makefile.m4
@@ -7,14 +7,14 @@ bldPRODUCT_START(`executable', `sendmail
 define(`bldBIN_TYPE', `G')
 define(`bldINSTALL_DIR', `')
 define(`bldSOURCES', `main.c alias.c arpadate.c bf.c collect.c conf.c control.c convtime.c daemon.c deliver.c domain.c envelope.c err.c headers.c macro.c map.c mci.c milter.c mime.c parseaddr.c queue.c ratectrl.c readcf.c recipient.c sasl.c savemail.c sfsasl.c shmticklib.c sm_resolve.c srvrsmtp.c stab.c stats.c sysexits.c timers.c tls.c trace.c udb.c usersmtp.c util.c version.c ')
+APPENDDEF(`bldSOURCES',`blacklist.c ')
 PREPENDDEF(`confENVDEF', `confMAPDEF')
 bldPUSH_SMLIB(`sm')
 bldPUSH_SMLIB(`smutil')
 
 
 dnl hack: /etc/mail is not defined as "location of .cf" in the build system
-define(`bldTARGET_INST_DEP', ifdef(`confINST_DEP', `confINST_DEP',
-`${DESTDIR}/etc/mail/submit.cf ${DESTDIR}${MSPQ}'))dnl
+define(`bldTARGET_INST_DEP', ifdef(`confINST_DEP', `confINST_DEP'))
 define(`bldTARGET_LINKS', ifdef(`confLINKS', `confLINKS',
 `${DESTDIR}${UBINDIR}/newaliases ${DESTDIR}${UBINDIR}/mailq ${DESTDIR}${UBINDIR}/hoststat ${DESTDIR}${UBINDIR}/purgestat')
 )dnl
