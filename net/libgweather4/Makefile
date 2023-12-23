PORTNAME=	libgweather
PORTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome
PKGNAMESUFFIX=	4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access online weather information
WWW=		https://www.gnome.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
LIB_DEPENDS=	libgeocode-glib-2.so:net/geocode-glib2 \
		libsoup-3.0.so:devel/libsoup3

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:build \
		shebangfix tar:xz vala:build
USE_GNOME=	gtk30 libxml2 pygobject3 introspection:build
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.GWeather4.enums.xml \
		org.gnome.GWeather4.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
