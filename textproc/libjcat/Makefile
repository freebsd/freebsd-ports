PORTNAME=	libjcat
DISTVERSION=	0.2.3
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/hughsie/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Library for reading and writing JSON catalog files
WWW=		https://github.com/hughsie/libjcat

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext-runtime gnome localbase:ldflags meson pkgconfig \
		python:build tar:xz vala:build
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgtkdoc=false -Dtests=false

.include <bsd.port.mk>
