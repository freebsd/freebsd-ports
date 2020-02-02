# $FreeBSD$

PORTNAME=	libhandy
PORTVERSION=	0.0.10
CATEGORIES=	x11-toolkits gnome
DIST_SUBDIR=	gnome

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
GL_COMMIT=	2d777677352d037b6f5cc24d9c1c8d9a74ac0ded

.include <bsd.port.mk>
