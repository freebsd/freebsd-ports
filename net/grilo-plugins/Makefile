# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	grilo-plugins
PORTVERSION=	0.2.17
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgrilo-0.2.so:net/grilo \
		libavahi-gobject.so:net/avahi-app \
		libgdata.so:devel/libgdata

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 intlhack libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-youtube \
		--enable-vimeo \
		--enable-freebox \
		--enable-tmdb
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/grilo-0.2/
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_SUB=			yes
OPTIONS_DEFINE=                 TRACKER DLEYNA DMAP METADATA
OPTIONS_DEFAULT=                TRACKER METADATA

TRACKER_DESC=			Tracker support for grilo (used by gnome-music and possibly others)
TRACKER_CONFIGURE_ENABLE=	tracker
TRACKER_LIB_DEPENDS=		libtracker-sparql-1.0.so:sysutils/tracker
DMAP_DESC=			DMAP (DAAP, DPAP & DACP) support with libdmapsharing
DMAP_CONFIGURE_ENABLE=		dmap
DMAP_LIB_DEPENDS=		libdmapsharing-3.0.so:net/libdmapsharing
DLEYNA_DESC=			DLNA support for grilo
DLEYNA_CONFIGURE_ENABLE=	dleyna
DLEYNA_LIB_DEPENDS=		libsoup-2.4.so:devel/libsoup
METADATA_DESC=			Enable Local-metadata plugin
METADATA_CONFIGURE_ENABLE=	localmetadata
METADATA_LIB_DEPENDS=		libmediaart-2.0.so:multimedia/libmediaart

.include <bsd.port.mk>
