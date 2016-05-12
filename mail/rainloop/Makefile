# $FreeBSD$

PORTNAME=	rainloop
PORTVERSION=	1.9.4
PORTREVISION=	1
CATEGORIES?=	mail www
MASTER_SITES=	http://repository.rainloop.net/v2/webmail/${PORTVERSION}/
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.${RBUILD}-${RHASH}

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Modern and interactive webmail

.if !defined(PKGNAMESUFFIX)
LICENSE=	RainLoop
LICENSE_NAME=	RainLoop Software License
LICENSE_TEXT=	License can be found at: http://www.rainloop.net/licensing/
LICENSE_PERMS=	auto-accept
.endif

.if !defined(PKGNAMESUFFIX)
# Refresh using info from http://repository.rainloop.net/v2/core.stable.json
RHASH=		e92836d3d764e6c6286a9374360b1474
.endif

.if defined(PKGNAMESUFFIX)
# Refresh using info from http://repository.rainloop.net/v2/core.open.json
RHASH=		36cc7daed043fcd4f32077bd5585349c
.endif

# Refresh using info from http://repository.rainloop.net/v2/core.(stable|open).json
RBUILD=		415

.if !defined(PKGNAMESUFFIX)
RESTRICTED=	Redistribution in any form is prohibited
.endif
USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
WANT_PHP_WEB=	yes
USE_PHP=	curl iconv json xml dom openssl pcre spl zlib
RVER=		${PORTVERSION}.${RBUILD}
PLIST_SUB=	VER="${RVER}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_RADIO=		DB
OPTIONS_RADIO_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} rainloop ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
