# Created by: Stefan Bethke <stb@lassitu.de>
# $FreeBSD$

PORTNAME=	ws2300
PORTVERSION=	1.9
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}-1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	stb@lassitu.de
COMMENT=	Driver for the LaCrosse WS-2300 weather station

LICENSE=	AGPLv3

USES=		python:2
USE_PYTHON=	distutils autoplist

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/ws2300 ${STAGEDIR}${PREFIX}/bin/ws2300
	${INSTALL_MAN} ${WRKSRC}/ws2300.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
