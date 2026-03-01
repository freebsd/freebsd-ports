PORTNAME=	msgraph
DISTVERSION=	0.3.4
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access MS Graph API for Office 365
WWW=		https://gnome.pages.gitlab.gnome.org/msgraph/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-3.0.so:devel/libsoup3

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS TEST
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

TEST_LIB_DEPENDS=	libuhttpmock-1.0.so:net/uhttpmock
TEST_USE=		gnome=libxml2
TEST_MESON_TRUE=	tests

.include <bsd.port.mk>
