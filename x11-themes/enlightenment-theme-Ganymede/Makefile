# New ports collection makefile for:	enlightenment-theme-Ganymede
# Date created:				08 Aug 2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	enlightenment-theme-Ganymede
PORTVERSION=	0.16.8
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment
DISTNAME=	${PORTNAME:S/enlightenment/e16/}-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A themes of enlightenment window menager

RUN_DEPENDS=	${X11BASE}/bin/enlightenment:${PORTSDIR}/x11-wm/enlightenment

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/e16

post-install:
	${CHOWN} -R root:wheel ${DATADIR}/themes/Ganymede

.include <bsd.port.mk>
