PORTNAME=	libshumate
DISTVERSION=	1.0.0.alpha.1
CATEGORIES=	x11-toolkits geography
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	-shortwave

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK4 widget to display maps (compatible with Shortwave)
WWW=		https://wiki.gnome.org/Projects/libshumate

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libgraphene-1.0.so:graphics/graphene

USES=		gnome meson pkgconfig sqlite tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build
USE_LDCONFIG=	yes

CONFLICTS=	libshumate
PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
