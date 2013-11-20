# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/libgweather3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgweather
PORTVERSION=	3.6.2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	libgweather-2.[0-9]*

NO_STAGE=	yes
LATEST_LINK=	libgweather3
USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehier gnomeprefix intlhack gconf2 ltverhack gtk30
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.GWeather.enums.xml \
		org.gnome.GWeather.gschema.xml

.include <bsd.port.mk>
