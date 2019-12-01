# $FreeBSD$

PORTNAME=	rss-bridge
PORTVERSION=	20190912
CATEGORIES=	www

MAINTAINER=	osidorkin@gmail.com
COMMENT=	RSS feed generator for websites missing it

LICENSE=	PD

USES=		php:web

USE_GITHUB=	yes
GH_ACCOUNT=	RSS-Bridge
GH_TAGNAME=	2019-09-12

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

USE_PHP=	curl json mbstring openssl simplexml

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=	SQLITE
SQLITE_DESC=		Enable sqlite-based cache support (requires sqlite)

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite3
COPY_SKIP_OPT=
PLIST_SUB+=	SQLITE=""
.else
COPY_SKIP_OPT=	-or -name SQLiteCache.php
PLIST_SUB+=	SQLITE="@comment "
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "-not ( \
	    -name LICENSE -or -name .gitkeep ${COPY_SKIP_OPT} )" )

.include <bsd.port.mk>
