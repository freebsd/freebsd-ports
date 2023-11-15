PORTNAME=	libadwaita
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES=	c579fbe0c10d2b761cfe1fe4e825aaa19fe81c77.patch:-p1 \
		3e3967d5f69180644519936991cad10136e84ca9.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Building blocks for modern GNOME applications
WWW=		https://www.gtk.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc:textproc/sassc
LIB_DEPENDS=	libappstream.so:devel/appstream \
		libfribidi.so:converters/fribidi \
		libgraphene-1.0.so:graphics/graphene

USES=		gettext gnome meson ninja pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
