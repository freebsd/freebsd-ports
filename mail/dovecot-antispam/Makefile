# Created by: Denis Shaposhnikov <dsh@wizard.volgograd.ru>
# $FreeBSD$

PORTNAME=	dovecot-antispam
PORTVERSION=	1.3
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

OPTIONS_DEFINE=	DSPAM MAILTRAIN DEBUG DEBUG_VERBOSE
OPTIONS_DEFAULT=	DSPAM
DSPAM_DESC=		Direct dspam training
MAILTRAIN_DESC=		send mail to special addresses for training
DEBUG_DESC=		Turn on debug information (syslog)
DEBUG_VERBOSE_DESC=	Turn on verbose debug

NO_STAGE=	yes
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
	${INSTALL_DATA} ${WRKSRC}/lib90_antispam_plugin.so \
		${PREFIX}/lib/dovecot/imap/
	${INSTALL_MAN} ${WRKSRC}/antispam.7 \
		${MANPREFIX}/man/man7/dovecot-antispam.7

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
