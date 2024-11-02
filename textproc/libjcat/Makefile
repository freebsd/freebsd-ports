PORTNAME=	libjcat
DISTVERSION=	0.2.2
CATEGORIES=	textproc

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Library for reading and writing JSON catalog files
WWW=		https://github.com/hughsie/libjcat

LICENSE=	LGPL21

BUILD_DEPENDS=	gobject-introspection>=1.36:devel/gobject-introspection \
		gtkdocize:textproc/gtk-doc \
		help2man:misc/help2man \
		${PYTHON_PKGNAMEPREFIX}elementpath>0:textproc/py-elementpath@${PY_FLAVOR}
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libhogweed.so:security/nettle \
		libjson-glib-1.0.so:devel/json-glib

USES=		gnome localbase:ldflags meson pkgconfig vala:build python
USE_GITHUB=	yes
GH_ACCOUNT=	hughsie
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
