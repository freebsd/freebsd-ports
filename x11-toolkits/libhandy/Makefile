PORTNAME=	libhandy
PORTVERSION=	1.2.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library with GTK+ widgets for mobile phones

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libgladeui-2.so:devel/glade

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false

.include <bsd.port.mk>
