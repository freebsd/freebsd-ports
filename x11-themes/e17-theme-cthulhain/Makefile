# New ports collection makefile for:	e17-theme-cthulhain
# Date created:		5 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	cthulhain
PORTVERSION=	0.4.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GET_E} \
		ftp://ftp.springdaemons.com/pub/snapshots/e17/
MASTER_SITE_SUBDIR=	Themes/E17
PKGNAMEPREFIX=	e17-theme-
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Cthulhain theme for use with e17 window manager

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
