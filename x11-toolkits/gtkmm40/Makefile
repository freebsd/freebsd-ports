PORTNAME=	gtkmm
PORTVERSION=	4.18.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	40
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ bindings for GTK 4
WWW=		https://gtkmm.gnome.org/

LICENSE=	LGPL21+

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libgraphene-1.0.so:graphics/graphene

USES=		compiler:c++17-lang gnome libtool meson pkgconfig \
		python:build tar:xz
USE_CXXSTD=	c++17
USE_GNOME=	gdkpixbuf gtk40 glibmm26 cairomm11 pangomm24
USE_LDCONFIG=	yes
MESON_ARGS=	-Dmaintainer-mode=false \
		-Dbuild-documentation=false \
		-Dbuild-demos=false \
		-Dbuild-tests=false

PLIST_SUB=	API_VERSION="4.0"

.include <bsd.port.mk>
