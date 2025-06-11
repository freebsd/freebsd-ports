PORTNAME=	amtk
DISTVERSION=	5.9.1
CATEGORIES=	x11-toolkits
DISTNAME=	libgedit-${PORTNAME}-${DISTVERSIONFULL}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Actions, Menus and Toolbars Kit
WWW=		https://gitlab.gnome.org/World/gedit/libgedit-amtk

LICENSE=	LGPL3

USES=		gettext gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20 gtk30 introspection:build

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit
GL_PROJECT=	libgedit-amtk

MESON_ARGS=	-Dgtk_doc=false \
		-Dtests=false

.include <bsd.port.mk>
