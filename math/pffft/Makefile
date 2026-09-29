PORTNAME=	pffft
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pretty Fast FFT (PFFFT) library
WWW=		https://github.com/marton78/pffft

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marton78

CMAKE_ON=	BUILD_SHARED_LIBS INSTALL_PFDSP INSTALL_PFFASTCONV
CMAKE_OFF=	PFFFT_BUILD_TESTS
CMAKE_TESTING_ON=	PFFFT_BUILD_TESTS

.include <bsd.port.options.mk> # for ARCH

.if ${ARCH:Mpowerpc*}
CMAKE_ARGS+=	-DPFFFT_USE_SIMD:BOOL=OFF #https://github.com/marton78/pffft/issues/55
.endif

.if ${ARCH} == i386
CFLAGS+=	-msse2
CXXFLAGS+=	-msse2 # fixes error: always_inline function '_mm_unpacklo_ps' requires target feature 'sse', but would be inlined into function 'pffft_zreorder' that is compiled without support for 'sse'
.endif

# tests as of 1.1.0: 100% tests passed, 0 tests failed out of 9

.include <bsd.port.mk>
