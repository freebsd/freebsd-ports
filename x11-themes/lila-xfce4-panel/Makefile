# New ports collection makefile for:	Lila-xfce4-panel
# Date created:		25 June 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	Lila-xfce4-panel
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-themes xfce
MASTER_SITES=	http://stief.tnux.net/Lila/
DIST_SUBDIR=	xfce4

MAINTAINER=	filippo@widestore.net
COMMENT=	XFce 4 Lila theme for xfce4 panel

RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

WRKSRC=		${WRKDIR}/Lila
USE_X_PREFIX=	yes

NO_BUILD=	yes

do-install:
	@${CP} -R ${WRKSRC} ${X11BASE}/share/xfce4/themes

.include <bsd.port.mk>
