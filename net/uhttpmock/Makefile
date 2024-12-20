PORTNAME=	uhttpmock
DISTVERSION=	0.11.0
CATEGORIES=	net gnome
MASTER_SITES=	http://tecnocode.co.uk/downloads/uhttpmock/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	HTTP web service mocking library for GNOME
WWW=		https://gitlab.com/groups/uhttpmock

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes
DOCSDIR=	${PREFIX}/share/gtk-doc
PORTDOCS=	html/*

OPTIONS_DEFINE=		DOCS VAPI

DOCS_MESON_TRUE=	gtk_doc
DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

VAPI_MESON_ENABLED=	vapi
VAPI_USES=		vala:build

.include <bsd.port.mk>
