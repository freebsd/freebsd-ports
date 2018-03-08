# Created by: Michael Fausten <ports@michael-fausten.de>
# $FreeBSD$

PORTNAME=	smarty
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.30
CATEGORIES=	www
PKGNAMESUFFIX=	3${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@michael-fausten.de
COMMENT=	PHP compiling template engine

LICENSE=	LGPL3

USES=		php:web,flavors
USE_PHP=	pcre
USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
