# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	backupchecker
PORTVERSION=	1.9
CATEGORIES=	sysutils archivers
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Fully automated backup checker

BROKEN=		unfetchable

LICENSE=	GPLv3

NO_ARCH=	yes

USES=		python:3.3+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s|'share','man'|'${MANPREFIX}/man'|" ${WRKSRC}/setup.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
