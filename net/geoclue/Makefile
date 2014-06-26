# Created by: Gustau Perez i Querol <gustau.perez@gmail.com> 
# $FreeBSD$
#   $MCom: ports/trunk/net/geoclue/Makefile 19754 2014-06-25 06:01:39Z gusi $

PORTNAME=	geoclue
PORTVERSION=	2.1.9
CATEGORIES=	net devel gnome
MASTER_SITES=	http://www.freedesktop.org/software/geoclue/releases/2.1/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus service that provides location information

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
	
USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomehier intlhack 
#USE_AUTOTOOLS=	autoconf automake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
#PATHFIX_MAKEFILEIN=	Makefile.am
CONFIGURE_ARGS=	--disable-3g-source \
		--disable-modem-gps-source
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

#pre-configure:
#		cd ${WRKSRC} && aclocal && autoconf

.include <bsd.port.mk>
