# New ports collection makefile for:	clickheat
# Date created:                27 June 2008
# Whom:                        Philippe Audeoud <jadawin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clickheat
PORTVERSION=	1.8
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	ClickHeat is a visual heatmap of clicks on a HTML page

USE_PHP=	gd session
WANT_PHP_WEB=	yes

NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME} \
		WWWDIR=${WWWDIR}

do-install:
	${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR} \
		"! -name README ! -name INSTALL ! -name LICENSE ! -name LISEZMOI ")
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
