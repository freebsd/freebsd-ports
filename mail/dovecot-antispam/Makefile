# Created by: Denis Shaposhnikov <dsh@wizard.volgograd.ru>
# $FreeBSD$

PORTNAME=	dovecot-antispam
PORTVERSION=	1.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://johannes.sipsolutions.net/download/dovecot-antispam/ \
		http://ports.internal.vlink.ru/distfiles/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Dovecot plugin to train dspam about spam or false positives

LICENSE=	GPLv2

BUILD_DEPENDS=	${NONEXISTENT}:mail/dovecot:configure
RUN_DEPENDS=	dovecot>=1.1.2:mail/dovecot

USES=		gmake tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/dovecot/imap

MAN7=		dovecot-antispam.7

OPTIONS_DEFINE=	DSPAM MAILTRAIN DEBUG DEBUG_VERBOSE
OPTIONS_DEFAULT=	DSPAM
DSPAM_DESC=		Direct dspam training
MAILTRAIN_DESC=		send mail to special addresses for training
DEBUG_DESC=		Turn on debug information (syslog)
DEBUG_VERBOSE_DESC=	Turn on verbose debug

.include <bsd.port.options.mk>

do-configure:
	DOVECOT=`${MAKE} -C ${PORTSDIR}/mail/dovecot -V WRKSRC` && \
		${ECHO} "DOVECOT=$$DOVECOT" > ${WRKSRC}/.config
.if ${PORT_OPTIONS:MDSPAM}
	${ECHO} "BACKEND=dspam-exec"  >> ${WRKSRC}/.config
.endif
.if ${PORT_OPTIONS:MMAILTRAIN}
	${ECHO} "BACKEND=mailtrain"  >> ${WRKSRC}/.config
.endif
.if ${PORT_OPTIONS:MDEBUG}
	${ECHO} "DEBUG=syslog"  >> ${WRKSRC}/.config
.endif
.if ${PORT_OPTIONS:MDEBUG_VERBOSE}
	${ECHO} "DEBUG_VERBOSE=1"  >> ${WRKSRC}/.config
.endif
	${ECHO} "PLUGINNAME=antispam" >> ${WRKSRC}/.config

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/dovecot/imap
	${INSTALL_DATA} -s ${WRKSRC}/lib90_antispam_plugin.so \
		${STAGEDIR}${PREFIX}/lib/dovecot/imap/
	${INSTALL_MAN} ${WRKSRC}/antispam.7 \
		${STAGEDIR}${MANPREFIX}/man/man7/dovecot-antispam.7

.include <bsd.port.mk>
