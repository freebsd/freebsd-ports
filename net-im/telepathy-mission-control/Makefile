# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-mission-control/Makefile,v 1.23 2012/08/17 19:06:46 kwm Exp $

PORTNAME=	telepathy-mission-control
PORTVERSION=	5.12.0
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-mission-control/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Telepathy component to apps to abstract details of connection managers

LIB_DEPENDS=	telepathy.2:${PORTSDIR}/net-im/libtelepathy \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix libxslt gnomehack ltverhack
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	im.telepathy.MissionControl.FromEmpathy.gschema.xml
CONFIGURE_ARGS=	--disable-upower

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/gtk-doc/html|/${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
