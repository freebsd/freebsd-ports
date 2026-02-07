PORTNAME=	libgweather
PORTVERSION=	40.0
PORTREVISION=	7
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access online weather information
WWW=		https://www.gnome.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgeocode-glib.so:net/geocode-glib \
		libsoup-2.4.so:devel/libsoup

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:build \
		shebangfix tar:xz vala:build
USE_GNOME=	gtk30 libxml2 pygobject3 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dglade_catalog=false
SHEBANG_FILES=	data/gen_locations_variant.py

GLIB_SCHEMAS=	org.gnome.GWeather.enums.xml \
		org.gnome.GWeather.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
