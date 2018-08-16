--- cf/ostype/bsd4.4.m4.orig	2014-03-05 00:59:45 UTC
+++ cf/ostype/bsd4.4.m4
@@ -17,4 +17,5 @@ divert(0)
 VERSIONID(`$Id: bsd4.4.m4,v 8.15 2013-11-22 20:51:15 ca Exp $')
 ifdef(`STATUS_FILE',, `define(`STATUS_FILE', `/var/log/sendmail.st')')dnl
 ifdef(`LOCAL_MAILER_PATH',, `define(`LOCAL_MAILER_PATH', /usr/libexec/mail.local)')dnl
+ifdef(`LOCAL_MAILER_ARGS',, `define(`LOCAL_MAILER_ARGS', `mail $u')')dnl
 ifdef(`UUCP_MAILER_ARGS',, `define(`UUCP_MAILER_ARGS', `uux - -r -z -a$g $h!rmail ($u)')')dnl
