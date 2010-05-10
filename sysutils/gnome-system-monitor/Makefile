# New ports collection makefile for:	gnomesystemmonitor
# Date created:				09 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-monitor/Makefile,v 1.139 2010/04/01 13:05:19 kwm Exp $
#

PORTNAME=	gnome-system-monitor
PORTVERSION=	2.28.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 system monitor program

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libwnck gnomevfs2 gnomedocutils \
		librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lutil"

GCONF_SCHEMAS=	gnome-system-monitor.schemas

.include <bsd.port.mk>
