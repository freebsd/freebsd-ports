# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chems
DISTVERSION=	0x04
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0x04

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The geekest content helper management system

NO_BUILD=	yes
USES=		zip php
USE_PHP=	xml iconv gd
PLIST_SUB=	WWWOWN="${WWWOWN}"
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}
	${MV} ${STAGEDIR}${WWWDIR}/usr/config.php ${STAGEDIR}${WWWDIR}/usr/config.php.sample

.include <bsd.port.mk>
