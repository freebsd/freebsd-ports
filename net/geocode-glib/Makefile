# Created by: Gustau Perez i Querol <gustau.perez@gmail.com> 
# $FreeBSD$
#   $MCom: ports-experimental/trunk/net/geocode-glib/Makefile 19425 2014-04-01 06:54:57Z gusi $

PORTNAME=	geocode-glib
PORTVERSION=	3.12.0
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convenience library for the geocoding and reverse geocoding

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 gnomehier intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|SoupGNOME|Soup|' \
                ${WRKSRC}/geocode-glib/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgeocode-glib.so.0

.include <bsd.port.mk>
