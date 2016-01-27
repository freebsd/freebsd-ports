# Created by: chinsan
# $FreeBSD$

PORTNAME=	phpsecinfo
PORTVERSION=	0.2.1
CATEGORIES=	security www
MASTER_SITES=	LOCAL/chinsan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP environment security auditing tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zip
USE_PHP=	pcre
WANT_PHP_WEB=	yes
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-20070406
TEMP_PLIST=	${WRKDIR}/temp-pkg-plist

PLIST_SUB=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
