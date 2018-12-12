# $FreeBSD$

PORTNAME=	libpagemaker
PORTVERSION=	0.0.4
PORTREVISION=	6
CATEGORIES=	print graphics devel
MASTER_SITES=	LODEV/${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Aldus/Adobe PageMaker documents

LICENSE=	MPL20

BUILD_DEPENDS=	${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:xz
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
