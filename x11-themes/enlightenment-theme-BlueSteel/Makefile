# New ports collection makefile for:	enlightenment-theme-BlueSteel
# Date created:				08 Aug 2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	enlightenment-theme-BlueSteel
PORTVERSION=	0.16.8
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	enlightenment
DISTNAME=	${PORTNAME:S/enlightenment/e16/}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A themes of enlightenment window menager

RUN_DEPENDS=	${LOCALBASE}/bin/e16:${PORTSDIR}/x11-wm/enlightenment

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/e16

post-install:
	${CHOWN} -R root:wheel ${DATADIR}/themes/BlueSteel

.include <bsd.port.mk>
