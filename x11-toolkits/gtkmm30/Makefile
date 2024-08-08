PORTNAME=	gtkmm
DISTVERSION=	3.24.9
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+3
WWW=		http://gtkmm.sourceforge.net/

LICENSE=	LGPL21

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang gnome localbase:ldflags meson \
		pkgconfig python:build tar:xz
USE_GNOME=	gdkpixbuf2 gtk30 glibmm cairomm atkmm pangomm
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbuild-documentation=false \
		-Dbuild-demos=false \
		-Dcpp_std=c++11

PLIST_SUB=	API_VERSION="3.0"

.include <bsd.port.mk>
