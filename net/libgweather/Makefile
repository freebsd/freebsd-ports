# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/libgweather/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libgweather
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

BUILD_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomehier gnomeprefix gtk30 intlhack \
		introspection:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.GWeather.enums.xml \
		org.gnome.GWeather.gschema.xml

.include <bsd.port.mk>
