PORTNAME=	geoclue
DISTVERSION=	2.7.1
CATEGORIES=	net devel gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus service that provides location information
WWW=		https://gitlab.freedesktop.org/geoclue/geoclue/wikis/home

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-3.0.so:devel/libsoup3

USES=		gettext gnome meson pkgconfig vala:build

USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_TAGNAME=	8a24f60969d4c235d9918796c38a6a9c42e10131

MESON_ARGS=	-D3g-source=false \
		-Dcdma-source=false \
		-Dnmea-source=false \
		-Dmodem-gps-source=false

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DEMO DOCS
OPTIONS_DEFAULT=	DEMO

DEMO_DESC=		Install geoclue (demo) agent
DEMO_LIB_DEPENDS=	libnotify.so:devel/libnotify
DEMO_MESON_TRUE=	demo-agent

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk-doc

.include <bsd.port.mk>
