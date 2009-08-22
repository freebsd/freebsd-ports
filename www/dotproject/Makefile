# New ports collection makefile for:	dotproject
# Date created:				12 April 2005
# Whom:					Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	dotproject
PORTVERSION=	2.1.2
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/dotProject%20Version%20${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open Source Project Management tool

WRKSRC=		${WRKDIR}/${PORTNAME}
DOTPROJECTDIR=	${PREFIX}/www/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	gd mysql session zlib
WANT_PHP_WEB=	yes
USE_APACHE=	1.3+
MAKE_JOBS_SAFE=	yes

SUB_LIST+=	DOTPROJECTDIR=${DOTPROJECTDIR}
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${DOTPROJECTDIR}
	${CP} -R ${WRKSRC}/* ${DOTPROJECTDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DOTPROJECTDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
