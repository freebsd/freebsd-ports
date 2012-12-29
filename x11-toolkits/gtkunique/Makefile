# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkunique
PORTVERSION=	0.9.1
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DIST_SUBDIR=	gnome2

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Single instance application library

USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_GNOME=	gtk20 ltverhack
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DBUS
OPTIONS_DEFAULT=	DBUS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	DBUS="" XLIBS="@comment "
.else
PLIST_SUB+=	DBUS="@comment " XLIBS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
