PORTNAME=	tracker
PORTVERSION=	2.3.4
PORTREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libsoup-2.4.so:devel/libsoup \
		libdbus-1.so:devel/dbus \
		libjson-glib-1.0.so:devel/json-glib \
		libicutu.so:devel/icu

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gnome localbase:ldflags meson \
		pkgconfig python:3.4+,build sqlite tar:xz
USE_GNOME=	glib20 introspection:build libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=false \
		-Dman=true \
		-Dnetwork_manager=disabled \
		-Dstemmer=disabled \
		-Dbash_completion=${PREFIX}/etc/bash_completion.d \
		-Dsystemd_user_services=no
GLIB_SCHEMAS=	org.freedesktop.Tracker.DB.gschema.xml \
		org.freedesktop.Tracker.FTS.gschema.xml \
		org.freedesktop.Tracker.Store.gschema.xml \
		org.freedesktop.Tracker.enums.xml \
		org.freedesktop.Tracker.gschema.xml
BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_SUB=	LIBVER=0.304.0

.include <bsd.port.mk>
