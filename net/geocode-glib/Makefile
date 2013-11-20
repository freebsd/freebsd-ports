# Created by: Gustau Perez i Querol <gustau.perez@gmail.com> 
# $FreeBSD$

PORTNAME=	geocode-glib
PORTVERSION=	0.99.0
CATEGORIES=	net devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convenience library for the Yahoo! Place Finder APIs

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

USES=		gettext gmake pathfix pkgconfig
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver3 gnomedocutils gnomehier intlhack ltverhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|SoupGNOME|Soup|' \
                ${WRKSRC}/geocode-glib/Makefile.in

.include <bsd.port.mk>
