# $FreeBSD$

PORTNAME=	libmspub
PORTVERSION=	0.0.6
CATEGORIES=	print graphics devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Microsoft Publisher file format

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/ptr_container/ptr_map.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		pathfix pkgconfig

CONFIGURE_ARGS=	--disable-werror --without-docs
CONFIGURE_ENV=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-lz"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
