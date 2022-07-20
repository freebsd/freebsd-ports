PORTNAME=	libgweather
PORTVERSION=	40.0
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access online weather information

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libgeocode-glib.so:net/geocode-glib \
		libsoup-2.4.so:devel/libsoup

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:3.6+,build \
		shebangfix tar:xz
USE_GNOME=	gtk30 libxml2 pygobject3 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dglade_catalog=false
SHEBANG_FILES=	data/gen_locations_variant.py

GLIB_SCHEMAS=	org.gnome.GWeather.enums.xml \
		org.gnome.GWeather.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
