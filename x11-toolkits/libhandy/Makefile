# $FreeBSD$

PORTNAME=	libhandy
PORTVERSION=	1.0.1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library with GTK+ widgets for mobile phones

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgladeui-2.so:devel/glade

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false

.include <bsd.port.mk>
