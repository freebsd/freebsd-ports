PORTNAME=	msgraph
DISTVERSION=	0.2.3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access MS Graph API for Office 365
WWW=		https://gnome.pages.gitlab.gnome.org/msgraph/

LIB_DEPENDS=    libgoa-1.0.so:net/gnome-online-accounts \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-3.0.so:devel/libsoup3

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-0
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS TEST

DOCS_MESON_TRUE=	gtk_doc
DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen

TEST_MESON_TRUE=	tests
TEST_LIB_DEPENDS=	libuhttpmock-1.0.so:net/uhttpmock

.include <bsd.port.mk>
