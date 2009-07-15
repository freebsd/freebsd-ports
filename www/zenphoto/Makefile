# New ports collection makefile for:   zenphoto
# Date created:                27 December 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	zenphoto
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zenphoto.org/files/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A simpler web photo gallery

USE_PHP=	mysql gd session mbstring gettext pcre json
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
		"! -name README.html ! -name License.txt ! -name Zenphoto.package")
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} 644 ${WWWDIR}/zp-core/images/*
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
