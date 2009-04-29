# New ports collection makefile for:	dotproject-devel
# Date created:				Mon Apr 30 07:53:48 EDT 2007
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	dotproject
PORTVERSION=	${DOTPROJECTVER}.${DEVELVERSION:C/^([a-z]).*/\1/}${DEVELVERSION:C/^[a-z]*//}
CATEGORIES=	www devel
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DOTPROJECTVER}-${DEVELVERSION}

MAINTAINER=	paul+ports@it.ca
COMMENT=	Open Source Project Management tool

DOTPROJECTVER=	2.1
DEVELVERSION=	rc1

OPTIONS=	JPGRAPH "Build gantt charts with graphics/jpgraph" on

WRKSRC=		${WRKDIR}/${PORTNAME}
DOTPROJECTDIR=	${PREFIX}/www/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	gd mysql session zlib
WANT_PHP_WEB=	yes
USE_APACHE=	1.3
USE_MYSQL=	yes

SUB_LIST+=	DOTPROJECTDIR=${DOTPROJECTDIR}
SUB_FILES=	pkg-message

.if defined(WITH_JPGRAPH)
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/webfonts/arial.ttf:${PORTSDIR}/x11-fonts/webfonts \
		${LOCALBASE}/share/jpgraph/jpgraph.php:${PORTSDIR}/graphics/jpgraph2
.endif

post-patch:
	@${FIND} ${WRKSRC} -name CVS -o -name *.orig | ${XARGS} ${RM}

do-install:
	${MKDIR} ${DOTPROJECTDIR}
	${CP} -R ${WRKSRC}/* ${DOTPROJECTDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DOTPROJECTDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
