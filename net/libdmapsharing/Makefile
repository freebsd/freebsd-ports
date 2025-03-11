PORTNAME=	libdmapsharing
PORTVERSION=	3.9.13
CATEGORIES=	net gnome
MASTER_SITES=	https://www.flyn.org/projects/libdmapsharing/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application
WWW=		https://www.flyn.org/projects/libdmapsharing

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libgee-0.8.so:devel/libgee

USES=		gettext gnome gmake gstreamer libtool pathfix pkgconfig vala:build
USE_GNOME=	gdkpixbuf gnomeprefix gtk30 introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	MDNS
OPTIONS_SINGLE_MDNS=	AVAHI MDNSRESPONDER
OPTIONS_DEFAULT=	AVAHI
OPTIONS_SUB=	yes

AVAHI_LIB_DEPENDS=	libavahi-core.so:net/avahi-app
AVAHI_CONFIGURE_ON=	--with-mdns=avahi

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

MDNSRESPONDER_BROKEN=		undefined references to mDNSResponder symbols
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_CONFIGURE_ON=	--with-mdns=mdns_sd

.include <bsd.port.options.mk>

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.mk>
