# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	folks
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to aggregates people from multiple sources

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgcr-base-3.so:security/gcr \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libnspr4.so:devel/nspr \
		libssl3.so:security/nss \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

USES=		gettext gnome localbase meson python:3.5+,build pkgconfig \
		readline sqlite tar:xz
USE_GNOME=	evolutiondataserver3 intlhack introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbluez_backend=false

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 LIBVERLONG=25.21.0

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	TRACKER
OPTIONS_DEFAULT=TRACKER
TRACKER_DESC=	Tracker backend

TRACKER_MESON_TRUE=	tracker_backend
TRACKER_LIB_DEPENDS=	libtracker-control-2.0.so:sysutils/tracker

.include <bsd.port.mk>
