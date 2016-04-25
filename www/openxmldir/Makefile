# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	openxmldir
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/open79xxdir/OpenXMLDir/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP based XML menuing system for Cisco 79xx IP phones

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

NO_BUILD=	yes
WANT_PHP_WEB=	yes
USE_PHP=	mysql xml
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
