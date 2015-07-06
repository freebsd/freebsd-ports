# $FreeBSD$

PORTNAME=	rainloop
PORTVERSION=	1.9.2
CATEGORIES?=	mail www
MASTER_SITES=	http://repository.rainloop.net/v2/webmail/${PORTVERSION}/
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.${RBUILD}-${RHASH}

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Modern and interactive webmail

.if !defined(PKGNAMESUFFIX)
LICENSE=	CCbyNCSA3
LICENSE_NAME=	Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_TEXT=	License can be found at: https://github.com/RainLoop/rainloop-webmail/blob/master/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
.endif

.if !defined(PKGNAMESUFFIX)
# Refresh using info from http://repository.rainloop.net/v2/core.stable.json
RHASH=		b21276cc22a92698f5813079b046334c
.endif

.if defined(PKGNAMESUFFIX)
# Refresh using info from http://repository.rainloop.net/v2/core.open.json
RHASH=		1579e1f742ef7a4fa87e55c201416e30
.endif

# Refresh using info from http://repository.rainloop.net/v2/core.(stable|open).json
RBUILD=		343

USES=		zip
NO_BUILD=	yes
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

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} rainloop ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
