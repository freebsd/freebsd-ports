# Created by: Gustau Perez i Querol <gustau.perez@gmail.com> 
# $FreeBSD$
#   $MCom: ports/trunk/net/geocode-glib/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	geocode-glib
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convenience library for the geocoding and reverse geocoding

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 gnomehier intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|SoupGNOME|Soup|' \
                ${WRKSRC}/geocode-glib/Makefile.in

.include <bsd.port.mk>
