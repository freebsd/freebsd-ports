# $FreeBSD$

PORTNAME=	rss-bridge
DISTVERSION=	2020-02-26
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	osidorkin@gmail.com
COMMENT=	RSS feed generator for websites missing it

LICENSE=	PD

USES=		php:web

USE_GITHUB=	yes
GH_ACCOUNT=	RSS-Bridge

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USE_PHP=	curl json mbstring openssl simplexml

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=SQLITE
OPTIONS_SUB=	yes

SQLITE_DESC=	Enable sqlite-based cache support (requires sqlite)

SQLITE_USE=	PHP=sqlite3

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "." ${STAGEDIR}${WWWDIR} "-not ( \
	    -name LICENSE -or -name .gitkeep )" )

.include <bsd.port.mk>
