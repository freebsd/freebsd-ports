PORTNAME=	smarty
PORTVERSION=	3.1.48
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMESUFFIX=	3${PHP_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP compiling template engine
WWW=		https://www.smarty.net/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php:flavors,web

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/smarty3${PHP_PKGNAMESUFFIX}
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

PORTSCOUT=	limit:^3\.

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
