# $FreeBSD$

PORTNAME=	amath
PORTVERSION=	1.8.0
CATEGORIES=	math
MASTER_SITES=	http://suyai.innolan.net/ \
		https://amath.innolan.net/

MAINTAINER=	cs@innolan.dk
COMMENT=	Simple command line calculator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Build with regression tests
OPTIONS_RADIO=	LIBM
OPTIONS_RADIO_LIBM=	APPLIBM OPENLIBM SYSLIBM
LIBM_DESC=	Math libraries
APPLIBM_DESC=	Build and install application libraries
OPENLIBM_DESC=	Build with OpenLibm
SYSLIBM_DESC=	System (-lm)
OPTIONS_DEFAULT=	APPLIBM TESTS
OPTIONS_SUB=	yes

SYSLIBM_CONFIGURE_WITH=	libm
OPENLIBM_CONFIGURE_WITH=	openlibm
OPENLIBM_LIB_DEPENDS=	libopenlibm.so:math/openlibm
TESTS_CONFIGURE_ENABLE=	test

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --pkgconfig=libdata/pkgconfig \
		--mandir=man LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
MAKE_ARGS=	CC=${CC} CXX=${CXX}
ALL_TARGET=	static
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
