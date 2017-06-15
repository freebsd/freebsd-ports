# Created by: Michael Fausten <ports@michael-fausten.de>
# $FreeBSD$

PORTNAME=	smarty
PORTVERSION=	3.1.29
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www
PKGNAMESUFFIX=	3

MAINTAINER=	ports@michael-fausten.de
COMMENT=	PHP compiling template engine

LICENSE=	LGPL3

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
