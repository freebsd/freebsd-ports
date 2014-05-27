# Created by: Jose Liang <jose@jose.idv.tw>
# $FreeBSD$

PORTNAME=	simplog
PORTVERSION=	0.9.3.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9.3.2:src
DISTFILES=	${PORTNAME}-0.9.3.2.tar.gz:src \
		${PORTNAME}_update_only-${PORTVERSION}.tar.gz:update

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete and powerful blogging tool

LICENSE=	GPLv2

NO_BUILD=	yes
SUB_FILES=	pkg-message
WRKSRC?=	${WRKDIR}/simplog
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-extract:
	${RMDIR} ${WRKSRC}/cache

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${CP} -r * ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
