PORTNAME=	libpanel
PORTVERSION=	1.10.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IDE paneling library for GTK
WWW=		https://gitlab.gnome.org/GNOME/libpanel/

LICENSE=	LGPL3+

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		gettext-tools gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	cairo glib20 gtk40 introspection:build libadwaita

MESON_ARGS=	-Dintrospection=enabled \
		-Ddocs=disabled

.include <bsd.port.mk>
