# New ports collection makefile for:	enlightenment-theme-BrushedMetal-Tigert
# Date created:				08 Aug 2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	enlightenment-theme-BrushedMetal-Tigert
PORTVERSION=	0.16
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A themes of enlightenment window menager

RUN_DEPENDS=	${X11BASE}/bin/enlightenment:${PORTSDIR}/x11-wm/enlightenment

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
NO_BUILD=	yes

post-install:
	${CHOWN} -R root:wheel ${X11BASE}/share/enlightenment/themes/BrushedMetal-Tigert

.include <bsd.port.mk>
