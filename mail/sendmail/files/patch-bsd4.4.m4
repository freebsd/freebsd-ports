--- cf/ostype/bsd4.4.m4.orig	1999-04-24 07:37:40.000000000 +0200
+++ cf/ostype/bsd4.4.m4	2008-05-04 11:55:42.000000000 +0200
@@ -17,4 +17,5 @@
 VERSIONID(`$Id: bsd4.4.m4,v 8.14 1999/04/24 05:37:40 gshapiro Exp $')
 ifdef(`STATUS_FILE',, `define(`STATUS_FILE', `/var/log/sendmail.st')')dnl
 ifdef(`LOCAL_MAILER_PATH',, `define(`LOCAL_MAILER_PATH', /usr/libexec/mail.local)')dnl
+ifdef(`LOCAL_MAILER_ARGS',, `define(`LOCAL_MAILER_ARGS', `mail $u')')dnl
 ifdef(`UUCP_MAILER_ARGS',, `define(`UUCP_MAILER_ARGS', `uux - -r -z -a$g $h!rmail ($u)')')dnl
