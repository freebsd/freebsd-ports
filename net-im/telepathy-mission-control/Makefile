# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/branches/GNOME_3_12/net-im/telepathy-mission-control/Makefile 19917 2014-09-25 22:47:02Z kwm $

PORTNAME=	telepathy-mission-control
PORTVERSION=	5.16.2
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-mission-control/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Telepathy component to apps to abstract details of connection managers

LIB_DEPENDS=	libtelepathy.so:${PORTSDIR}/net-im/libtelepathy \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--disable-upower
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	im.telepathy.MissionControl.FromEmpathy.gschema.xml
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
