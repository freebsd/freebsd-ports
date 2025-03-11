PORTNAME=	grilo
PORTVERSION=	0.3.16
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework focused on making media discovery and browsing
WWW=		https://wiki.gnome.org/Grilo

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		liboauth.so:net/liboauth \
		libtotem-plparser.so:multimedia/totem-pl-parser

USES=		cpe gettext gnome localbase meson pathfix pkgconfig \
		python:build tar:xz vala:build
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build libxml2
BINARY_ALIAS=	python=${PYTHON_VERSION}

MESON_ARGS=	-Denable-gtk-doc=false -Dsoup3=true

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	UI

UI_DESC=	Enable testing UI
UI_MESON_TRUE=	enable-test-ui
UI_USE=		GNOME=gdkpixbuf,gtk30

PLIST_SUB+=	LIBVER=316

.include <bsd.port.mk>
