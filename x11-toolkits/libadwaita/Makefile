PORTNAME=	libadwaita
PORTVERSION=	1.1.0
CATEGORIES=	x11-toolkits

# WARNING: ABI is unstable, often breaks Rust-based consumers e.g., solanum, authenticator.
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
GL_COMMIT=	0e57660217829b3f905f20e1c53aaf42c2302882

PORTSCOUT=	limit:1,even

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
