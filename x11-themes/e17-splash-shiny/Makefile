# New ports collection makefile for:	e17-splash-shiny
# Date created:		4 Aug 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	shiny
PORTVERSION=	1.0
CATEGORIES=	x11-themes
MASTER_SITES=	http://www0.get-e.org/Themes/Startup/_files/
PKGNAMEPREFIX=	e17-splash-
DISTNAME=	init_shiny_reflection
EXTRACT_SUFX=	.edj

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Shiny splash screen for e17 window manager

RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/init/init_shiny_reflection.edj

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/init
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${PREFIX}/share/enlightenment/data/init

.include <bsd.port.mk>
