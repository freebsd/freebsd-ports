# New ports collection makefile for:	gnomesystemmonitor
# Date created:				09 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomesystemmonitor
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-monitor/2.6
DISTNAME=	gnome-system-monitor-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 system monitor program

LIB_DEPENDS=	gtop-2.0.2:${PORTSDIR}/devel/libgtop2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix intlhack lthack gnomehack libgnomeui libwnck
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lutil"

.include <bsd.port.mk>
