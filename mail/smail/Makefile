# New ports collection makefile for:	smail
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	smail
PORTVERSION=	3.2.0.114
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/ \
		ftp://ftp.planix.com/pub/Smail/ \
		ftp://ftp.fu-berlin.de/unix/mail/smail/ \
		ftp://ftp.weird.com/pub/local/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program used for receiving and delivering mail

CONFLICTS=	bsmtp-*

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident

CONFLICTS=	courier-0.* postfix-1.* postfix-2.* sendmail-8.* sendmail-*-8.* zmailer-2.*
INSTALL_TARGET=	install installman

MAN1=		pathto.1 uuwho.1 uupath.1
MAN5=		smailconf.5 smail.5 smaildrct.5 smailmeth.5 smailqual.5 \
		smailrtrs.5 smailrtry.5 smailtrns.5
MAN8=		pathalias.8 mkdbm.8 mkline.8 mksort.8 mkaliases.8 smail.8 \
		mkpath.8 pathmerge.8 checkerr.8 getmap.8 mkhpath.8 savelog.8 \
		mkuuwho.8 mailq.8 sendmail.8 runq.8 rmail.8 rsmtp.8 smtpd.8 \
		newaliases.8 smailbug.8 unfreezemail.8 bouncemail.8

post-install:
	@${ECHO_MSG} "If you want to replace sendmail with links to smail, type"
	@${ECHO_MSG} "the following command as \"root\":"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      make replace"

.include <bsd.port.pre.mk>

replace:
.if ${OSVERSION} >= 400014
	@${ECHO_MSG} "===> Activating smail in /etc/mail/mailer.conf"
	${MV} -f /etc/mail/mailer.conf /etc/mail/mailer.conf.bak
	@${ECHO_CMD} "#" > /etc/mail/mailer.conf
	@${ECHO_CMD} -n "# Execute the smail sendmail program" >> /etc/mail/mailer.conf
	@${ECHO_CMD} ", named ${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "#" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "sendmail	${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "send-mail	${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "mailq		${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "newaliases	${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
.else
	@${ECHO_MSG} "===> Replacing sendmail programs"
	if [ -e /usr/sbin/sendmail ]; then \
		${MV} -f /usr/sbin/sendmail /usr/sbin/sendmail.BAK; \
		if [ -f /usr/sbin/sendmail.BAK ]; then \
			${CHMOD} 0 /usr/sbin/sendmail.BAK; \
		fi;\
	fi
	if [ -e ${PREFIX}/bin/smail ]; then \
		${LN} -s ${PREFIX}/bin/smail /usr/sbin/sendmail; \
	fi
	if [ -f /usr/sbin/mailstats ]; then \
		${CHMOD} 0 /usr/sbin/mailstats; \
	fi
	if [ -e /usr/bin/newaliases ]; then \
		${MV} -f /usr/bin/newaliases /usr/bin/newaliases.BAK; \
		if [ -f /usr/bin/newaliases.BAK ]; then \
			${CHMOD} 0 /usr/bin/newaliases.BAK; \
		fi;\
	fi
	if [ -e ${PREFIX}/bin/newaliases ]; then \
		${LN} -s ${PREFIX}/bin/newaliases /usr/bin/newaliases; \
	fi
	if [ -e /usr/bin/mailq ]; then \
		${MV} -f /usr/bin/mailq /usr/bin/mailq.BAK; \
		if [ -f /usr/bin/mailq.BAK ]; then \
			${CHMOD} 0 /usr/bin/mailq.BAK; \
		fi;\
	fi
	if [ -e ${PREFIX}/bin/mailq ]; then \
		${LN} -s ${PREFIX}/bin/mailq /usr/bin/mailq; \
	fi
.endif

.include <bsd.port.post.mk>
