# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/grilo-plugins/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	grilo-plugins
PORTVERSION=	0.2.12
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgrilo-0.2.so:${PORTSDIR}/net/grilo \
		libavahi-gobject.so:${PORTSDIR}/net/avahi-app \
		libgdata.so:${PORTSDIR}/devel/libgdata

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomehier intlhack libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-youtube \
		--enable-vimeo \
		--enable-freebox \
		--enable-tmdb
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/grilo-0.2/
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_SUB=			yes
OPTIONS_DEFINE=                 TRACKER UPNP DMAP
OPTIONS_DEFAULT=                TRACKER
TRACKER_DESC=			Tracker support for grilo (used by gnome-music and possibly others)
TRACKER_CONFIGURE_ENABLE=	tracker	
TRACKER_LIB_DEPENDS=		libtracker-sparql-1.0.so:${PORTSDIR}/sysutils/tracker
DMAP_DESC=			DMAP (DAAP, DPAP & DACP) support with libdmapsharing
DMAP_CONFIGURE_ENABLE=		dmap
DMAP_LIB_DEPENDS=		libdmapsharing-3.0.so:${PORTSDIR}/net/libdmapsharing
UPNP_CONFIGURE_ENABLE=		upnp
UPNP_LIB_DEPENDS=		libgupnp-1.0.so:${PORTSDIR}/net/gupnp \
				libgupnp-av-1.0.so:${PORTSDIR}/net/gupnp-av

.include <bsd.port.mk>
