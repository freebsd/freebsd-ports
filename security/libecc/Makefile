# Created by: ijliao
# $FreeBSD$

PORTNAME=	libecc
PORTVERSION=	0.14.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	C++ Elliptic Curve Library

LICENSE=	GPLv2+

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		libtool localbase
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's@endian\.h@sys/&@' \
	    ${WRKSRC}/include/libecc/bitset.h

.include <bsd.port.mk>
