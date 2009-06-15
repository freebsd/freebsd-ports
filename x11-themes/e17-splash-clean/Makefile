# New ports collection makefile for:	e17-splash-clean
# Date created:		11 March 2007
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	clean
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		${MASTER_SITE_GET_E}
MASTER_SITE_SUBDIR=	Themes/E17_-_Startup
PKGNAMEPREFIX=	e17-splash-
DISTNAME=	init_${PORTNAME}
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Clean splash screen for e17 window manager

RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/init/${DISTNAME}${EXTRACT_SUFX}

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/init
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${PREFIX}/share/enlightenment/data/init

.include <bsd.port.mk>
