PORTNAME=	smarty
DISTVERSIONPREFIX=	v
PORTVERSION=	3.1.45
CATEGORIES=	www
PKGNAMESUFFIX=	3${PHP_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP compiling template engine

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php:flavors,web
USE_PHP=	pcre

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/smarty3${PHP_PKGNAMESUFFIX}
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
