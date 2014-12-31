# $FreeBSD$

PORTNAME=	rainloop
PORTVERSION=	1.7.1
CATEGORIES?=	mail www
MASTER_SITES=	SF/${PORTNAME}-webmail/

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Modern and interactive webmail

LICENSE=	CCbyNCSA3
LICENSE_NAME=	Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_TEXT=	License can be found at: https://github.com/RainLoop/rainloop-webmail/blob/master/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
WANT_PHP_WEB=	yes
USE_PHP=	curl iconv json xml dom openssl pcre spl zlib
RVER=		1.7.1.215
PLIST_SUB=	VER="${RVER}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
# @TODO: PDO also for different backends

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} rainloop ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
