PORTNAME=	sleef
DISTVERSION=	3.9.0
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	SIMD Library for Evaluating Elementary Functions, vectorized libm
WWW=		https://sleef.org

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	tlfloat>0:math/tlfloat
LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libfftw3.so:math/fftw3
TEST_DEPENDS=	tlfloat>0:math/tlfloat

USES=		cmake:testing compiler:c11 pathfix pkgconfig ssl
CMAKE_ARGS=	-DSLEEF_BUILD_SHARED_LIBS:BOOL=ON	\
		-DSLEEF_DISABLE_FLOAT128:BOOL=ON
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

CMAKE_OFF=	SLEEF_BUILD_TESTS
CMAKE_TESTING_ON=	SLEEF_BUILD_TESTS

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*} || ${ARCH:Marmv?}
PLIST_SUB+=	GNUABI="@comment "
.else
PLIST_SUB+=	GNUABI=""
.endif

.include <bsd.port.mk>
