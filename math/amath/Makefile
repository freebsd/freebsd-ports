# $FreeBSD$

PORTNAME=	amath
PORTVERSION=	1.7.0
CATEGORIES=	math
MASTER_SITES=	http://suyai.innolan.net/

MAINTAINER=	cs@innolan.dk
COMMENT=	Simple command line calculator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --pkgconfig=libdata/pkgconfig
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
MAKE_ARGS=	CC=${CC} CXX=${CXX}
ALL_TARGET=	static
TEST_TARGET=	test

post-install:
	${LN} -sf libamathapp.so ${STAGEDIR}${PREFIX}/lib/amath/libamathapp.so.1
	${LN} -sf libamathcplex.so ${STAGEDIR}${PREFIX}/lib/amath/libamathcplex.so.1
	${LN} -sf libamathc.so ${STAGEDIR}${PREFIX}/lib/amath/libamathc.so.1
	${LN} -sf libamath.so ${STAGEDIR}${PREFIX}/lib/amath/libamath.so.1

.include <bsd.port.mk>
