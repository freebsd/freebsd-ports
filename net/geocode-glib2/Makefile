PORTNAME=	geocode-glib
PORTVERSION=	3.26.4
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convenience library for the geocoding and reverse geocoding
WWW=		https://git.gnome.org/browse/geocode-glib

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	geocode-glib>0:net/geocode-glib # for icons

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Denable-installed-tests=false \
		-Dsoup2=false

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	enable-gtk-doc
DOCSDIR=		${PREFIX}/share/gtk-doc/html/geocode-glib

.include <bsd.port.mk>
