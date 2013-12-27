# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkunique
PORTVERSION=	0.9.1
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single instance application library

USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk20 ltverhack
USE_LDCONFIG=	yes
USES=		gettext pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DBUS
OPTIONS_DEFAULT=	DBUS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	DBUS="" XLIBS="@comment "
.else
PLIST_SUB+=	DBUS="@comment " XLIBS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror ||' ${WRKSRC}/configure

.include <bsd.port.mk>
