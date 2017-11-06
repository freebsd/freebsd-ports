# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	grilo-plugins
PORTVERSION=	0.3.4
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
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libsoup-2.4.so:devel/libsoup \
		libmediaart-2.0.so:multimedia/libmediaart \
		libgmime-2.6.so:mail/gmime26 \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext gmake gnome libtool pathfix pkgconfig sqlite tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 intlhack libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lua-factory
INSTALL_TARGET=	install-strip

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			TRACKER DMAP
OPTIONS_DEFAULT=		TRACKER

TRACKER_DESC=			Tracker support for grilo (used by gnome-music and possibly others)
TRACKER_CONFIGURE_ENABLE=	tracker
TRACKER_LIB_DEPENDS=		libtracker-sparql-1.0.so:sysutils/tracker

DMAP_DESC=			DMAP (DAAP, DPAP & DACP) support with libdmapsharing
DMAP_CONFIGURE_ENABLE=		dmap
DMAP_LIB_DEPENDS=		libdmapsharing-3.0.so:net/libdmapsharing

.include <bsd.port.mk>
