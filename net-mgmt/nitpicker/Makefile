# Created by: Michael Reifenberger
# $FreeBSD$

PORTNAME=	nitpicker
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nitpicker.de/

MAINTAINER=	mr@FreeBSD.org
COMMENT=	IP flow Accounting tools

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nitpicker ${LOCALBASE}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/parse_flowfile/src/parse_flowfile ${LOCALBASE}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/dumpit/dumpit ${LOCALBASE}/bin

.include <bsd.port.mk>
