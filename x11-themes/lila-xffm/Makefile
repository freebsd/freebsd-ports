# New ports collection makefile for:	Lila-xffm
# Date created:		25 June 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	Lila-xffm
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11-themes xfce
MASTER_SITES=	http://stief.tnux.net/Lila/
DIST_SUBDIR=	xfce4

MAINTAINER=	filippo@widestore.net
COMMENT=	XFce 4 Lila icons for xffm4

RUN_DEPENDS=	xffm:${PORTSDIR}/x11-fm/xfce4-fm

WRKSRC=		${WRKDIR}/Lila
USE_X_PREFIX=	yes

NO_BUILD=	yes

do-install:
	@${CP} -R ${WRKSRC} ${X11BASE}/share/xffm/pixmaps/

.include <bsd.port.mk>
