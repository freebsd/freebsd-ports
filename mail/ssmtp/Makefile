# New ports collection makefile for:	ssmtp
# Date created:		9 Jan 2001
# Whom:			Tomasz Paszkowski <ns88@k.pl>
#
# $FreeBSD$
#

PORTNAME=	ssmtp
PORTVERSION=	2.38
CATEGORIES=	mail
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/s/ssmtp/ \
		ftp://ftp.icm.edu.pl/pub/Linux/debian/pool/main/s/ssmtp/
DISTNAME=	ssmtp_2.38-9

IGNORE=		configures the hostname at compiletime instead of installtime

MAINTAINER=	ns88@k.pl

WRKSRC=		${WRKDIR}/ssmtp-2.38
USE_GMAKE=	true
MAN8=		ssmtp.8

pre-install:
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 0755 \
	${PREFIX}/etc/ssmtp

post-install:
	@PREFIX="${PREFIX}" ${SH} ${PKGINSTALL}
	@${ECHO_MSG} --------------------------------------------------
	@${ECHO_MSG}
	@${ECHO_MSG} "To replace sendmail with ssmtp type make replace"
	@${ECHO_MSG}
	@${ECHO_MSG} --------------------------------------------------

.include <bsd.port.pre.mk>

replace:
.if ${OSVERSION} >= 400014
	@${ECHO} backuping old /etc/mail/mailer.conf
	@${MV} -f /etc/mail/mailer.conf /etc/mail/mailer.conf.old-ssmtp
	@${ECHO} Replacing mailwarpper config
	@${ECHO_CMD} "sendmail		${PREFIX}/sbin/ssmtp" > /etc/mail/mailer.conf
	@${ECHO_CMD} "send-mail		${PREFIX}/sbin/ssmtp" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "mailq			/bin/echo" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "newaliases		/bin/echo" >> /etc/mail/mailer.conf
.else
	@${ECHO} backuping old /usr/sbin/sendmail
	@${MV} -f /usr/sbin/sendmail /usr/sbin/sendmail.OFF
	@${CHMOD} 000 /usr/sbin/sendmail.OFF
	@${LN} -s ${PREFIX}/sbin/ssmtp /usr/sbin/sendmail
	@${ECHO} Done !
.endif

.include <bsd.port.post.mk>
