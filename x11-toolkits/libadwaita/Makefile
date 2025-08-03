PORTNAME=	libadwaita
PORTVERSION=	1.7.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Building blocks for modern adaptive GNOME applications
WWW=		https://gitlab.gnome.org/GNOME/libadwaita

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc:textproc/sassc
LIB_DEPENDS=	libappstream.so:devel/appstream \
		libfribidi.so:converters/fribidi \
		libgraphene-1.0.so:graphics/graphene

USES=		gettext-tools gnome meson ninja pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf gtk40 introspection:build

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
