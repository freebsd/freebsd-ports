# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	grilo
PORTVERSION=	0.2.7
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Grilo is a framework focused on making media discovery and browsing

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		liboauth.so:${PORTSDIR}/net/liboauth

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomehier intlhack introspection:build libxml2 ltverhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vala -disable-debug
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

#  --enable-debug include debug symbols
CONFIGURE_ARGS+=--enable-tests #          build unit tests

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	UI

UI_DESC=	Enable testing UI
UI_CONFIGURE_ENABLE=test-ui
UI_USE=		GNOME=gtk30

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgrilo-0.2.so.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgrlnet-0.2.so.0 

.include <bsd.port.mk>
