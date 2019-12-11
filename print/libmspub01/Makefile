# $FreeBSD$

PORTNAME=	libmspub
PORTVERSION=	0.1.4
PORTREVISION=	14
CATEGORIES=	print graphics devel
MASTER_SITES=	LODEV/${PORTNAME}
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Microsoft Publisher file format

LICENSE=	MPL20

BUILD_DEPENDS=	${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:xz
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
