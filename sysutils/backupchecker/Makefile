# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	backupchecker
PORTVERSION=	1.7
CATEGORIES=	sysutils archivers

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Fully automated backup checker

LICENSE=	GPLv3

USE_GITHUB=	yes

USES=	python:3.3+
USE_PYTHON=	distutils noegginfo

# XXX Handle UTF-8 '(c)' character within setup.py's header
MAKE_ENV+=	LC_ALL=en_US.UTF-8

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX} \
		PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}

PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} "s|'share','man'|'${MANPREFIX}/man'|" ${WRKSRC}/setup.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
