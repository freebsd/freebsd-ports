# $FreeBSD$

PORTNAME=	libpagemaker
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	print graphics devel
MASTER_SITES=	LIBREOFFICE_DEV

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Aldus/Adobe PageMaker documents

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig tar:xz
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
