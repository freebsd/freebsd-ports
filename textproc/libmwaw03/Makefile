# $FreeBSD$

PORTNAME=	libmwaw
PORTVERSION=	0.3.14
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	03

MAINTAINER=	office@FreeBSD.org
COMMENT=	Import library for some old mac text documents

LICENSE=	LGPL21+ MPL20
LICENSE_COMB=	dual

BROKEN_powerpc64=	fails to compile: MWAWCell.cxx:644: #pragma GCC diagnostic not allowed inside functions

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
