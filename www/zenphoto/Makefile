# New ports collection makefile for:   zenphoto
# Date created:                27 December 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	zenphoto
PORTVERSION=	1.1.4
CATEGORIES=	www
MASTER_SITES=	http://www.zenphoto.org/files/

MAINTAINER=	jadawin@tuxaco.net
COMMENT=	A simpler web photo gallery

USE_PHP=	mysql gd session
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
		"! -name README.html ! -name License.txt")
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
