PORTNAME=	libecc
PORTVERSION=	0.14.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	C++ Elliptic Curve Library
WWW=		https://libecc.sourceforge.net/

LICENSE=	GPLv2+

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		libtool localbase
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's@endian\.h@sys/&@' \
	    ${WRKSRC}/include/libecc/bitset.h

.include <bsd.port.mk>
