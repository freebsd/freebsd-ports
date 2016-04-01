# Created by: ijliao
# $FreeBSD$

PORTNAME=	libecc
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C++ Elliptic Curve Library

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${PREFIX}/lib -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's@endian\.h@sys/&@' ${WRKSRC}/include/libecc/bitset.h

.include <bsd.port.mk>
