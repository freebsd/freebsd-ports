# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	geoclue
PORTVERSION=	2.5.5
CATEGORIES=	net devel gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus service that provides location information

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libnotify.so:devel/libnotify

USES=		gettext gnome meson pkgconfig tar:xz

USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	9519d67c7a9a0e97a75115f9ff99d4fb0bb81b21

MESON_ARGS=	-D3g-source=false \
		-Dcdma-source=false \
		-Dnmea-source=false \
		-Dmodem-gps-source=false

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DEMO DOCS

DEMO_DESC=		Install geoclue demo agent
DEMO_LIB_DEPENDS=	libnotify.so:devel/libnotify
DEMO_MESON_TRUE=	demo-agent

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk-doc

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/geoclue/geoclue.conf \
		${STAGEDIR}${PREFIX}/etc/geoclue/geoclue.conf.sample

.include <bsd.port.mk>
