# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	folks
PORTVERSION=	0.10.1
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libzeitgeist-1.0.so:${PORTSDIR}/sysutils/libzeitgeist \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.4.[0-9]*

USE_LDCONFIG=	yes
USES=		gettext libtool gmake pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 intlhack \
		introspection:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-bluez-backend
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=deprecated-declarations
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=42 LIBVERLONG=25.17.3

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SOCIALWEB TRACKER
OPTIONS_DEFAULT=SOCIALWEB TRACKER
SOCIALWEB_DESC=	Social web backend
TRACKER_DESC=	Tracker backend
SOCIALWEB_CONFIGURE_ENABLE=	libsocialweb-backend
SOCIALWEB_LIB_DEPENDS=	libsocialweb.so:${PORTSDIR}/www/libsocialweb
TRACKER_CONFIGURE_ENABLE=	tracker-backend
TRACKER_LIB_DEPENDS=	libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker

post-patch:
	@${REINPLACE_CMD} -e 's|--fatal-warnings||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
