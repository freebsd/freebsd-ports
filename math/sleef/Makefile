PORTNAME=	sleef
DISTVERSION=	3.8
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIMD Library for Evaluating Elementary Functions, vectorized libm
WWW=		https://sleef.org

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libfftw3.so:math/fftw3

USES=		cmake:testing compiler:c11 pathfix ssl
CMAKE_ARGS=	-DSLEEF_BUILD_SHARED_LIBS:BOOL=ON
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
