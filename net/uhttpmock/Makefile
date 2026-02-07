PORTNAME=	uhttpmock
PORTVERSION=	0.11.0
CATEGORIES=	net gnome
MASTER_SITES=	http://tecnocode.co.uk/downloads/uhttpmock/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	HTTP web service mocking library
WWW=		https://gitlab.freedesktop.org/pwithnall/uhttpmock

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3

USES=		gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
