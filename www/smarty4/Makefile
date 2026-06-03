PORTNAME=	smarty
PORTVERSION=	4.5.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMESUFFIX=	4${PHP_PKGNAMESUFFIX}

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

PORTSCOUT=	limit:^4\.

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
