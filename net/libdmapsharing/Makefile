# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/libdmapsharing/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libdmapsharing
PORTVERSION=	2.9.24
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	https://www.flyn.org/projects/libdmapsharing/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application

LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgee-0.8.so:${PORTSDIR}/devel/libgee
BUILD_DEPENDS=	vala-vapigen>=0.16:${PORTSDIR}/lang/vala-vapigen

USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk20 introspection:build
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-introspection	\
		--with-mdns=avahi
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags gtk+-3.0`
LDFLAGS+=	-L${LOCALBASE}/lib `pkg-config --libs gtk+-3.0`
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_SINGLE=	MDNS
OPTIONS_SINGLE_MDNS=	AVAHI MDNSRESPONDER
AVAHI_LIB_DEPENDS=	libavahi-core.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_ON=	--with-mdns=avahi
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:${PORTSDIR}/net/mDNSResponder \
				libavahi-glib.so:${PORTSDIR}/net/avahi-app
MDNSRESPONDER_CONFIGURE_ON=	--with-mdns=mdns
MDNSRESPONDER_DESC+=	Zeroconf support via mDNSResponder (broken)

.include <bsd.port.mk>
