# New ports collection makefile for:	xfce4-weather-plugin
# Date created:		04 April 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	misc xfce geography
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 weather module for xfce4-panel

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack libxml2 pkgconfig
USE_XFCE=	configenv libgui libutil panel

post-patch:
# Patch taken from https://bugzilla.xfce.org/show_bug.cgi?id=8105#c9 
	@${REINPLACE_CMD} -e 's|1121946239|1003666583| ; \
		s|3c4cd39ee5dec84f|4128909340a9b2fc|' \
		${WRKSRC}/panel-plugin/weather.h

.include <bsd.port.mk>
