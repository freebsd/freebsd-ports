PORTNAME=	libgweather
PORTVERSION=	4.4.4
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome
PKGNAMESUFFIX=	4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access online weather information
WWW=		https://gitlab.gnome/GNOME/libgweather

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
LIB_DEPENDS=	libgeocode-glib-2.so:net/geocode-glib2 \
		libsoup-3.0.so:devel/libsoup3 \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext gnome localbase meson pkgconfig python:build \
		shebangfix tar:xz vala:build
USE_GNOME=	glib20 gtk30 libxml2 introspection:build pygobject3
USE_LDCONFIG=	yes
SHEBANG_FILES=	build-aux/meson/gen_locations_variant.py

MESON_ARGS=	-Dtests=false

GLIB_SCHEMAS=	org.gnome.GWeather4.enums.xml \
		org.gnome.GWeather4.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
