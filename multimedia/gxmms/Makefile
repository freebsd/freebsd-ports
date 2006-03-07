# New ports collection makefile for:	gxmms
# Date created:				3 November 2004
# Whom:					Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	gxmms
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	A simple GNOME panel applet for controlling XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomepanel gnomeprefix intlhack
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
