# New ports collection makefile for:	e17-theme-darkness
# Date created:		22 August 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	darkness
PORTVERSION=	0.99.037.3
CATEGORIES=	x11-themes
MASTER_SITES=	http://www0.get-e.org/Themes/E17/_files/ \
		ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-theme-
DISTNAME=	${PORTNAME}_by_saturn_vk
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Darkness theme for use with e17 window manager

RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel

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
