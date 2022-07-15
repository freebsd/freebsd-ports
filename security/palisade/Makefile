PORTNAME=	palisade
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.6
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PALISADE lattice cryptography library for Fully Homomorphic Encryption

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build: a declaration of 'Mul128' must be available
BROKEN_powerpc64=	fails to build: math/native_int/binint.h:510:11: error: Architecture not supported for MultD()
BROKEN_armv6=	configure fails: ** ERROR ** OpenMP is not installed

BUILD_DEPENDS=	autoconf:devel/autoconf # possibly a mistake in the project

USES=		cmake:noninja,testing localbase # compiler:c++11-lang
USE_GITLAB=	yes
USE_GITHUB=	nodefault
GL_PROJECT=	palisade-release # there's also palisade-development
GL_COMMIT=	0860127401ab794591f931fa2c61426c7b56ee2d
GH_TUPLE=	\
		JerryRyan:cereal:a384b101:cereal/third-party/cereal \
		google:benchmark:e451e50e:benchmark/third-party/google-benchmark \
		google:googletest:8b4817e3:google_test/third-party/google-test
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_UNITTESTS BUILD_EXAMPLES BUILD_BENCHMARKS
CMAKE_OFF+=	WITH_NTL # https://gitlab.com/palisade/palisade-development/-/issues/180
CMAKE_ARGS=	-DWITH_NTL=Y # libntl.so will be discontinued in 1.11, see https://gitlab.com/palisade/palisade-development/-/issues/180
CMAKE_TESTING_ON=	BUILD_UNITTESTS
CMAKE_TESTING_TARGET=	testall

CXXFLAGS+=	-I${WRKSRC}/third-party/google-test/googletest

BINARY_ALIAS=	git=false

LDFLAGS+=	-pthread # only for tests: see https://gitlab.com/palisade/palisade-release/-/issues/23

OPTIONS_DEFINE=		OPENMP HEXL
OPTIONS_DEFAULT=	OPENMP

HEXL_DESC=		Use Intel Hexl Library

OPENMP_CMAKE_BOOL=	WITH_OPENMP
HEXL_CMAKE_BOOL=	WITH_HEXL
HEXL_LIB_DEPENDS=	libhexl.so:security/hexl

.include <bsd.port.mk>
