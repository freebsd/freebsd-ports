PORTNAME=	libdmapsharing
PORTVERSION=	2.9.41
CATEGORIES=	net gnome
MASTER_SITES=	https://www.flyn.org/projects/libdmapsharing/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libgee-0.8.so:devel/libgee

USES=		gettext gnome gmake gstreamer libtool pathfix pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix gtk30 introspection:build
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-gtk-doc \
		--disable-introspection \
		--with-mdns=avahi
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags gtk+-3.0`
LDFLAGS+=	-L${LOCALBASE}/lib `pkg-config --libs gtk+-3.0` -lm
INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	AVAHI
OPTIONS_SINGLE=	MDNS
OPTIONS_SINGLE_MDNS=	AVAHI MDNSRESPONDER
AVAHI_LIB_DEPENDS=	libavahi-core.so:net/avahi-app
AVAHI_CONFIGURE_ON=	--with-mdns=avahi
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder \
				libavahi-glib.so:net/avahi-app
MDNSRESPONDER_CONFIGURE_ON=	--with-mdns=mdns
MDNSRESPONDER_DESC+=	Zeroconf support via mDNSResponder (broken)

.include <bsd.port.mk>
