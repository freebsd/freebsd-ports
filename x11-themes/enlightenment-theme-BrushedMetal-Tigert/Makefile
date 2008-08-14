# New ports collection makefile for:	enlightenment-theme-BrushedMetal-Tigert
# Date created:				08 Aug 2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	enlightenment-theme-BrushedMetal-Tigert
PORTVERSION=	0.16.8
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	enlightenment
DISTNAME=	e16-theme-BrushedMetal-Tigert-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A themes of enlightenment window menager

RUN_DEPENDS=	${LOCALBASE}/bin/e16:${PORTSDIR}/x11-wm/enlightenment

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/e16

post-install:
	${CHOWN} -R root:wheel ${DATADIR}/themes/BrushedMetal-Tigert

.include <bsd.port.mk>
