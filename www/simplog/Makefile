# Created by: Jose Liang <jose@jose.idv.tw>
# $FreeBSD$

PORTNAME=	simplog
PORTVERSION=	0.9.3.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9.3.2:src
DISTFILES=	${PORTNAME}-0.9.3.2.tar.gz:src \
		${PORTNAME}_update_only-${PORTVERSION}.tar.gz:update

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete and powerful blogging tool

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message
WRKSRC?=	${WRKDIR}/simplog
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${CP} -r * ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
