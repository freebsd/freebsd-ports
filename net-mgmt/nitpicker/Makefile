# Created by: Michael Reifenberger
# $FreeBSD$

PORTNAME=	nitpicker
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nitpicker.de/

MAINTAINER=	mr@FreeBSD.org
COMMENT=	IP flow Accounting tools

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nitpicker ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/parse_flowfile/src/parse_flowfile \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/dumpit/dumpit \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
