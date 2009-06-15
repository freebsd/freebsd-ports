# New ports collection makefile for:	e17-theme-dali
# Date created:		11 March 2007
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	dali
PORTVERSION=	4.1b
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GET_E} \
		ftp://ftp.springdaemons.com/pub/snapshots/e17/
MASTER_SITE_SUBDIR=	Themes/E17
PKGNAMEPREFIX=	e17-theme-
DISTNAME=	${PORTNAME}${PORTVERSION:S,.,,}
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Dali theme for use with e17 window manager

RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/themes/${DISTNAME}${EXTRACT_SUFX}

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/themes
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${PREFIX}/share/enlightenment/data/themes

.include <bsd.port.mk>
