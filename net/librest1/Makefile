PORTNAME=	librest
DISTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	net devel gnome
PKGNAMESUFFIX=	1
MASTER_SITES=	GNOME/sources/rest
DISTNAME=	rest-${DISTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME REST library
WWW=		https://gitlab.gnome.org/GNOME/librest

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-3.0.so:devel/libsoup3

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python tar:xz
USE_GNOME=	glib20 gtksourceview5 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dca_certificates=true \
		-Dca_certificates_path=/etc/ssl/cert.pem \
		-Dgtk_doc=false

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
