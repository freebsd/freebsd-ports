# Created by: mkptools
# $FreeBSD$

PORTNAME=	achievo
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	misc www
MASTER_SITES=	http://www.achievo.org/files/ \
		http://www.caomhin.org/geek/ports/
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}

MAINTAINER=	kevin@caomhin.demon.co.uk
COMMENT=	Flexible web-based resource management tool

BROKEN=		unfetchable

USES=	php:mod

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	YES

ACHVODIR?=	www/achievo
PLIST_SUB=	ACHVODIR=${ACHVODIR} WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

post-patch:
	@${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php-default

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ACHVODIR}
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/${ACHVODIR}

.include <bsd.port.mk>
