# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	grilo-plugins
PORTVERSION=	0.3.8
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgrilo-0.3.so:net/grilo \
		libavahi-gobject.so:net/avahi-app \
		libgdata.so:devel/libgdata \
		liboauth.so:net/liboauth \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgom-1.0.so:databases/gom \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libsoup-2.4.so:devel/libsoup \
		libmediaart-2.0.so:multimedia/libmediaart \
		libgmime-2.6.so:mail/gmime26 \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext gperf gnome meson pathfix pkgconfig sqlite tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 intlhack libxml2
USE_GSTREAMER1=	chromaprint
MESON_ARGS=	-Denable-lua-factory=no

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			TRACKER DMAP
OPTIONS_DEFAULT=		TRACKER

TRACKER_DESC=			Tracker support for grilo (used by gnome-music and possibly others)
TRACKER_MESON_YES=		enable-tracker
TRACKER_LIB_DEPENDS=		libtracker-sparql-2.0.so:sysutils/tracker

DMAP_DESC=			DMAP (DAAP, DPAP & DACP) support with libdmapsharing
DMAP_MESON_YES=			enable-dmap
DMAP_LIB_DEPENDS=		libdmapsharing-3.0.so:net/libdmapsharing

.include <bsd.port.mk>
