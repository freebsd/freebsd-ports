# New ports collection makefile for:   bpft
# Date created:        26 August 2002
# Whom:            El Vampiro <vampiro@rootshell.ru>
#
# $FreeBSD$

PORTNAME=	bpft
PORTVERSION=	4.0
CATEGORIES=	net
MASTER_SITES=	http://bpft.by.ru/ \
		ftp://vampiro.rootshell.ru/pub/FreeBSD/distfiles/
EXTRACT_SUFX=	_29-07-2002.tgz

MAINTAINER=	vampiro@rootshell.ru

WRKSRC=		${WRKDIR}/bpft
MAN1=		traflog.1 trafstat.1
MAN8=		trafstatd.8 trafd.8
MANCOMPRESSED=	yes

pre-everything:
	@${ECHO_MSG}
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG} "!!!                         WARNING                           !!!"
	@${ECHO_MSG} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO_MSG}
	@${ECHO_MSG} "This port uses original trafd binaries layout"
	@${ECHO_MSG} "Original trafd and bpft binaries layout are mutually exclusive"
	@${ECHO_MSG}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/WhatsNew ${DOCSDIR}
	${STRIP_CMD} ${PREFIX}/sbin/trafd
	${STRIP_CMD} ${PREFIX}/sbin/trafstatd
	${STRIP_CMD} ${PREFIX}/bin/trafstat
	${STRIP_CMD} ${PREFIX}/bin/traflog

.include <bsd.port.mk>
