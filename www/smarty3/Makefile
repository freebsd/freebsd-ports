# Created by: Michael Fausten <ports@michael-fausten.de>
# $FreeBSD$

PORTNAME=	smarty3
PORTVERSION=	3.1.29
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	ports@michael-fausten.de
COMMENT=	PHP compiling template engine

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/smarty-${PORTVERSION}

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php
GH_PROJECT=	smarty

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
