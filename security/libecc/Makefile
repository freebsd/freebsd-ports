# ex:ts=8
# Ports collection makefile for:	libecc
# Date created:			Oct 29, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libecc
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@stack.nl
COMMENT=	C++ Elliptic Curve Library

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} 's@endian\.h@sys/&@' ${WRKSRC}/include/libecc/bitset.h

.include <bsd.port.mk>
