PORTNAME=	sleef
DISTVERSION=	3.9.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD Library for Evaluating Elementary Functions, vectorized libm
WWW=		https://sleef.org

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	tlfloat>0:math/tlfloat
TEST_DEPENDS=	fftw3>0:math/fftw3 \
		fftw3-float>0:math/fftw3-float \
		gmp>0:math/gmp \
		mpfr>0:math/mpfr \
		tlfloat>0:math/tlfloat

USES=		cmake:testing compiler:c11 pathfix pkgconfig
.if make(test)
USES+=		ssl
.endif
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

# CPUTYPE breaks unit tests and presumably the library itself
.if defined(CPUTYPE) && ${ARCH} == amd64
CPUTYPE=
.endif

CMAKE_TESTING_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenSSL \
			SLEEF_DISABLE_FFTW
CMAKE_TESTING_ON=	SLEEF_BUILD_TESTS \
			SLEEF_ENABLE_MPFR \
			SLEEF_ENABLE_SSL

CMAKE_OFF=	SLEEF_BUILD_TESTS \
		SLEEF_ENABLE_MPFR \
		SLEEF_ENABLE_SSL

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_OpenSSL \
		SLEEF_BUILD_SHARED_LIBS \
		SLEEF_DISABLE_FLOAT128 \
		SLEEF_DISABLE_FFTW \
		SLEEF_ENABLE_TLFLOAT

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*} || ${ARCH:Marmv?}
PLIST_SUB+=	GNUABI="@comment "
.else
PLIST_SUB+=	GNUABI=""
.endif

.include <bsd.port.mk>
