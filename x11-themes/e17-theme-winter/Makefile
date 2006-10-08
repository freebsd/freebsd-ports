# New ports collection makefile for:	e17-theme-winter
# Date created:		5 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	winter
PORTVERSION=	1.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www0.get-e.org/Themes/E17/_files/ \
		http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	e17-theme-
DISTNAME=	winter-e17
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Winter theme for use with e17 window manager

RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/themes/winter-e17.edj

IGNORE=		doesn't work with recent e17
DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2006-11-01

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/themes
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${PREFIX}/share/enlightenment/data/themes

.include <bsd.port.mk>
