# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/grilo-plugins/Makefile 19596 2014-04-28 20:14:19Z gusi $

PORTNAME=	grilo-plugins
PORTVERSION=	0.2.12
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgrilo-0.2.so:${PORTSDIR}/net/grilo \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libdmapsharing-3.0.so:${PORTSDIR}/net/libdmapsharing \
		libgupnp-1.0.so:${PORTSDIR}/net/gupnp \
		libgupnp-av-1.0.so:${PORTSDIR}/net/gupnp-av

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomehier intlhack libxml2 
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-youtube \
		--enable-vimeo \
		--enable-freebox \
		--enable-tmbd \
		--enable-dmap \
		--enable-upnp
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/grilo-0.2/
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SUB=			yes
OPTIONS_DEFINE=                 TRACKER
OPTIONS_DEFAULT=                TRACKER
TRACKER_CONFIGURE_ENABLE=	migration
TRACKER_LIB_DEPENDS=		libtracker-sparql-1.0.so:${PORTSDIR}/sysutils/tracker
TRACKER_DESC=			Tracker support for grilo (used by gnome-music and possibly others)

.include <bsd.port.mk>
