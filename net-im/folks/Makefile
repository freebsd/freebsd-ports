PORTNAME=	folks
PORTVERSION=	0.15.9
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to aggregates people from multiple sources
WWW=		https://gitlab.gnome.org/GNOME/folks

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee

USES=		gettext gnome localbase meson python:build pkgconfig \
		readline sqlite tar:xz vala:build
USE_GNOME=	glib20 evolutiondataserver3 introspection:build libxml2
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbluez_backend=false \
		-Dtelepathy_backend=false \
		-Dtests=false \
		-Dinstalled_tests=false

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=26 LIBVERLONG=26.0.0

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
