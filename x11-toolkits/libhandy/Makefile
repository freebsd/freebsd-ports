PORTNAME=	libhandy
PORTVERSION=	1.8.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library with GTK widgets for mobile phones
WWW=		https://gnome.pages.gitlab.gnome.org/libhandy/

LICENSE=	LGPL21+

LIB_DEPENDS=	libfribidi.so:converters/fribidi

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf gtk30 introspection:build

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false \
		-Dglade_catalog=disabled

.include <bsd.port.mk>
