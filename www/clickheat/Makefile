# Created by: Philippe Audeoud <jadawin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clickheat
PORTVERSION=	1.14
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	ClickHeat is a visual heatmap of clicks on a HTML page

USE_ZIP=	yes
USE_PHP=	gd session
WANT_PHP_WEB=	yes

NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME} \
		WWWDIR=${WWWDIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR} \
		"! -name README ! -name INSTALL ! -name LICENSE ! -name LISEZMOI ")
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
