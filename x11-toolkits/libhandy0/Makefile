PORTNAME=	libhandy
PORTVERSION=	0.0.13
CATEGORIES=	x11-toolkits gnome
DIST_SUBDIR=	gnome
PKGNAMESUFFIX=	0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library with GTK+ widgets for mobile phones

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgladeui-2.so:devel/glade

USES=		compiler:c11 gettext gnome meson pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false

USE_GITLAB=	yes
GL_SITE=	https://source.puri.sm/
GL_ACCOUNT=	Librem5
GL_COMMIT=	7a193d7692c9c76a1a94f17c4d30b585f77d177c

.include <bsd.port.mk>
