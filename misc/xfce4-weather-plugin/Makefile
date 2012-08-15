# New ports collection makefile for:	xfce4-weather-plugin
# Date created:		04 April 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.8.1
CATEGORIES=	misc xfce geography
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 weather module for xfce4-panel

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack libxml2
USE_XFCE=	configenv libmenu libutil panel
USE_PKGCONFIG=	build

.include <bsd.port.mk>
