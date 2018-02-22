# Created by: Stefan Bethke <stb@lassitu.de>
# $FreeBSD$

PORTNAME=	ws2300
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}-1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	stb@lassitu.de
COMMENT=	Driver for the LaCrosse WS-2300 weather station

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/agpl-3.0.txt

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PLIST_FILES=	bin/ws2300 man/man1/ws2300.1.gz

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/ws2300 ${STAGEDIR}${PREFIX}/bin/ws2300
	${INSTALL_MAN} ${WRKSRC}/ws2300.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
