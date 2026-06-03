PORTNAME=	librest
PORTVERSION=	0.10.2
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	1
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME REST library
WWW=		https://gitlab.gnome.org/GNOME/librest

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-3.0.so:devel/libsoup3

PORTSCOUT=	limitw:1,even

USES=		gettext-tools gnome localbase meson pkgconfig python tar:xz
USE_GNOME=	glib20 introspection:build libadwaita libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Dca_certificates=true \
		-Dca_certificates_path=/etc/ssl/cert.pem

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	gtk_doc

EXAMPLES_USE=		gnome=gtksourceview5
EXAMPLES_MESON_TRUE=	examples

.include <bsd.port.mk>
