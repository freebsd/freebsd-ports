PORTNAME=	libshumate
DISTVERSION=	1.1.1
CATEGORIES=	x11-toolkits geography
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK4 widget to display maps
WWW=		https://wiki.gnome.org/Projects/libshumate

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libgraphene-1.0.so:graphics/graphene

USES=		gettext gnome meson pkgconfig sqlite tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dsysprof=disabled

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
