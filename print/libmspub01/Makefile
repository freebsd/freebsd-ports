# $FreeBSD$

PORTNAME=	libmspub
PORTVERSION=	0.1.2
PORTREVISION=	7
CATEGORIES=	print graphics devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/${PORTNAME}/
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Microsoft Publisher file format

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/ptr_container/ptr_map.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		compiler:c++0x libtool pathfix pkgconfig tar:xz
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
