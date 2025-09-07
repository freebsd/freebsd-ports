PORTNAME=	smarty
PORTVERSION=	5.5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP compiling template engine
WWW=		https://www.smarty.net/ \
		https://github.com/smarty-php/smarty

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php:flavors,web

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/smarty${PHP_PKGNAMESUFFIX}
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
