# New ports collection makefile for:	e17-theme-carbon
# Date created:		5 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	carbon
PORTVERSION=	0.1.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www0.get-e.org/Themes/E17/_files/ \
		http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	e17-theme-
DISTNAME=	carbon_themes_pack
EXTRACT_SUFX=	.zip

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Carbon theme for use with e17 window manager

RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/themes/Carbon-14.edj

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/themes
	${INSTALL_DATA} ${WRKSRC}/carbon_themes_pack/e17/Carbon-14.edj \
		${PREFIX}/share/enlightenment/data/themes

.include <bsd.port.mk>
