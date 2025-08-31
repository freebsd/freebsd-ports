PORTNAME=	geoclue
DISTVERSION=	2.8.0
CATEGORIES=	net devel gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus service that provides location information
WWW=		https://gitlab.freedesktop.org/geoclue/geoclue/wikis/home

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-3.0.so:devel/libsoup3

USES=		gettext-tools gnome meson pkgconfig python shebangfix tar:bz2 \
		vala:build

USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
SHEBANG_FILES=	interface/create-unified-xml.py

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org

MESON_ARGS=	-D3g-source=false \
		-Dcdma-source=false \
		-Dnmea-source=false \
		-Dmodem-gps-source=false \
		-Dwifi-source=false

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DEMO DOCS
OPTIONS_DEFAULT=	DEMO

DEMO_DESC=		Install geoclue (demo) agent
DEMO_LIB_DEPENDS=	libnotify.so:devel/libnotify
DEMO_MESON_TRUE=	demo-agent

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk-doc

.include <bsd.port.mk>
