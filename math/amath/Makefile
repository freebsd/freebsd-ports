# $FreeBSD$

PORTNAME=	amath
PORTVERSION=	1.8.5
CATEGORIES=	math
MASTER_SITES=	http://dist1.innolan.net/ \
		http://dist2.innolan.net/ \
		https://amath.innolan.net/

MAINTAINER=	cs@innolan.net
COMMENT=	Simple command line calculator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Must define endianness

USES=		gmake
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --pkgconfig=libdata/pkgconfig \
		--mandir=man LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	CC=${CC} CXX=${CXX}

OPTIONS_DEFINE=	TESTS
OPTIONS_DEFAULT=APPLIBM
OPTIONS_RADIO=	LIBM
OPTIONS_RADIO_LIBM=	APPLIBM OPENLIBM SYSLIBM
OPTIONS_SUB=	yes
APPLIBM_DESC=	Build and install application libraries
LIBM_DESC=	Math libraries
OPENLIBM_DESC=	Build with OpenLibm
SYSLIBM_DESC=	System (-lm)
TESTS_DESC=	Build with regression tests

OPENLIBM_CONFIGURE_WITH=	openlibm
OPENLIBM_LIB_DEPENDS=	libopenlibm.so:math/openlibm
SYSLIBM_CONFIGURE_WITH=	libm
TESTS_CONFIGURE_ENABLE=	test

TEST_TARGET=	test

post-install-APPLIBM-on:
	${LN} -sf libamathapp.so ${STAGEDIR}${PREFIX}/lib/amath/libamathapp.so.1
	${LN} -sf libamathcplex.so ${STAGEDIR}${PREFIX}/lib/amath/libamathcplex.so.1
	${LN} -sf libamathc.so ${STAGEDIR}${PREFIX}/lib/amath/libamathc.so.1
	${LN} -sf libamath.so ${STAGEDIR}${PREFIX}/lib/amath/libamath.so.1

do-install-APPLIBM-off:
	${INSTALL_PROGRAM} ${WRKSRC}/amath ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/amath.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
