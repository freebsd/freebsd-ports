# $FreeBSD$

PORTNAME=	rainloop
PORTVERSION=	1.8.2
DISTVERSIONSUFFIX=	.${RBUILD}-${RHASH}
PORTREVISION=	1
CATEGORIES?=	mail www
MASTER_SITES=	http://repository.rainloop.net/v2/webmail/${PORTVERSION}/

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Modern and interactive webmail

LICENSE=	CCbyNCSA3
LICENSE_NAME=	Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_TEXT=	License can be found at: https://github.com/RainLoop/rainloop-webmail/blob/master/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

# Refresh using info from http://repository.rainloop.net/v2/core.stable.json
RHASH=		3cd56183a7425a8750c19bc688aedd81
RBUILD=		291

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} rainloop ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
