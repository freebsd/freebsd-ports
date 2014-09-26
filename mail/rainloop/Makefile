# $FreeBSD$

PORTNAME=	rainloop
PORTVERSION=	1.6.9
CATEGORIES?=	mail www
MASTER_SITES=	SF/${PORTNAME}-webmail/

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Modern and interactive webmail

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
WANT_PHP_WEB=	yes
USE_PHP=	curl iconv json xml dom openssl pcre spl zlib
RVER=		${PORTVERSION}.164
PLIST_SUB=	VER="${RVER}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
# @TODO: PDO also for different backends

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${EXTRACT_CMD} -d ${WRKSRC} ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} > /dev/null

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
