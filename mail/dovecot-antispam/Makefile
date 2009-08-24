# New ports collection makefile for:	dovecot-antispam
# Date created:		Sat Jan  5 16:31:30 MSK 2008
# Whom:			Denis Shaposhnikov <dsh@wizard.volgograd.ru>
#
# $FreeBSD$
#

PORTNAME=	dovecot-antispam
PORTVERSION=	1.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://johannes.sipsolutions.net/download/dovecot-antispam/ \
		http://ports.internal.vlink.ru/distfiles/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Dovecot plugin to train dspam about spam or false positives

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:configure
RUN_DEPENDS=	dovecot>=1.1.2:${PORTSDIR}/mail/dovecot

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/dovecot/imap

MAN7=		dovecot-antispam.7

OPTIONS+=	DSPAM "direct dspam training" on
OPTIONS+=	MAILTRAIN "send mail to special addresses for training" off
OPTIONS+=	DEBUG "Turn on debug information (syslog)" off
OPTIONS+=	DEBUG_VERBOSE "Turn on verbose debug" off

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib90_antispam_plugin.so \
		${PREFIX}/lib/dovecot/imap/
	${INSTALL_MAN} ${WRKSRC}/antispam.7 \
		${MANPREFIX}/man/man7/dovecot-antispam.7

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

do-configure:
	DOVECOT=`${MAKE} -C ${PORTSDIR}/mail/dovecot -V WRKSRC` && \
		${ECHO} "DOVECOT=$$DOVECOT" > ${WRKSRC}/.config
.if defined(WITH_DSPAM)
	${ECHO} "BACKEND=dspam-exec"  >> ${WRKSRC}/.config
.endif
.if defined(WITH_MAILTRAIN)
	${ECHO} "BACKEND=mailtrain"  >> ${WRKSRC}/.config
.endif
.if defined(WITH_DEBUG)
	${ECHO} "DEBUG=syslog"  >> ${WRKSRC}/.config
.endif
.if defined(WITH_DEBUG_VERBOSE)
	${ECHO} "DEBUG_VERBOSE=1"  >> ${WRKSRC}/.config
.endif
	${ECHO} "PLUGINNAME=antispam" >> ${WRKSRC}/.config

.include <bsd.port.post.mk>
