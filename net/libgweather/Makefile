# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgweather
PORTVERSION=	3.24.1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access online weather information

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libgeocode-glib.so:net/geocode-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intltool introspection:build libxml2
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-glade-catalog
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.GWeather.enums.xml \
		org.gnome.GWeather.gschema.xml

.include <bsd.port.mk>
