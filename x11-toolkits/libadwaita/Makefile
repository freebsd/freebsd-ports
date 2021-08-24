PORTNAME=	libadwaita
PORTVERSION=	0.0.20210526
PORTREVISION=	3
CATEGORIES=	x11-toolkits

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Building blocks for modern GNOME applications

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc:textproc/sassc \
		valac:lang/vala
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libgraphene-1.0.so:graphics/graphene

USES=		gettext gnome meson ninja pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	7f61711633dfd067f4928df80afe6b14f16f886e

PORTSCOUT=	limit:1,even

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
