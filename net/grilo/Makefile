PORTNAME=	grilo
PORTVERSION=	0.3.14
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework focused on making media discovery and browsing

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		liboauth.so:net/liboauth \
		libtotem-plparser.so:multimedia/totem-pl-parser

USES=		cpe gettext gnome localbase meson pathfix pkgconfig \
		python:3.4+,build tar:xz
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build libxml2
BINARY_ALIAS=	python=${PYTHON_VERSION}

MESON_ARGS=	-Denable-gtk-doc=false

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	UI

UI_DESC=	Enable testing UI
UI_MESON_TRUE=	enable-test-ui
UI_USE=		GNOME=cairo,gdkpixbuf2,gtk30

.include <bsd.port.mk>
