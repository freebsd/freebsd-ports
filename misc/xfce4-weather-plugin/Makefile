# New ports collection makefile for:	xfce4-weather-plugin
# Date created:		04 April 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.7.3
PORTREVISION=	4
CATEGORIES=	misc xfce geography
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-weather-plugin/0.7/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	XFce 4 weather module for xfce4-panel

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget glib20 gtk20 intltool intlhack libxml2 pkgconfig
USE_XFCE=	configenv libgui libutil panel

.include <bsd.port.mk>
