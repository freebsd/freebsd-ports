# New ports collection makefile for: mailmgr
# Date created:         14 August 2003
# Whom:                 Hsin-Hsiung Chang
#
# $FreeBSD$
#

PORTNAME=	mailmgr
PORTVERSION=	1.2.3
CATEGORIES=	mail
MASTER_SITES=	http://sarg.sourceforge.net/

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	Sendmail Analysis Report Generator

GNU_CONFIGURE=	yes

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

do-install:
	${INSTALL_DATA} ${WRKSRC}/mailmgr.conf ${PREFIX}/etc/mailmgr.conf.default
.if !exists(${PREFIX}/etc/mailmgr.conf)
	${INSTALL_DATA} ${WRKSRC}/mailmgr.conf ${PREFIX}/etc/mailmgr.conf
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/mailmgr ${PREFIX}/bin
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
