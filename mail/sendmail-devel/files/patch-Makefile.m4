--- sendmail/Makefile.m4.orig	2019-02-15 10:30:19 UTC
+++ sendmail/Makefile.m4
@@ -7,6 +7,7 @@ bldPRODUCT_START(`executable', `sendmail
 define(`bldBIN_TYPE', `G')
 define(`bldINSTALL_DIR', `')
 define(`bldSOURCES', `main.c alias.c arpadate.c bf.c collect.c conf.c control.c convtime.c daemon.c deliver.c domain.c envelope.c err.c headers.c macro.c map.c mci.c milter.c mime.c parseaddr.c queue.c ratectrl.c readcf.c recipient.c sasl.c savemail.c sfsasl.c shmticklib.c sm_resolve.c srvrsmtp.c stab.c stats.c sysexits.c timers.c tlsh.c tls.c trace.c udb.c usersmtp.c util.c version.c ')
+APPENDDEF(`bldSOURCES',`blacklist.c ')
 PREPENDDEF(`confENVDEF', `confMAPDEF')
 bldPUSH_SMLIB(`sm')
 bldPUSH_SMLIB(`smutil')
