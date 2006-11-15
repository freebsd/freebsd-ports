# New ports collection makefile for:	dotproject
# Date created:				12 April 2005
# Whom:					Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	dotproject
PORTVERSION=	2.0.4
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	sailorfred@yahoo.com
COMMENT=	Open Source Project Management tool

WRKSRC=		${WRKDIR}/${PORTNAME}
DOTPROJECTDIR=	${PREFIX}/www/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	gd mysql session zlib
DEFAULT_PHP_VER=4
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=5
USE_APACHE=	1.3

SUB_LIST+=	DOTPROJECTDIR=${DOTPROJECTDIR}
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${DOTPROJECTDIR}
	${CP} -R ${WRKSRC}/* ${DOTPROJECTDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DOTPROJECTDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
