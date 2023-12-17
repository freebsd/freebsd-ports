PORTNAME=	openfhe
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source Fully Homomorphic Encryption library
WWW=		https://github.com/openfheorg/openfhe-development

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: error: __int128 is not supported on this target
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	autoconf:devel/autoconf # possibly a mistake in the project

USES=		cmake:noninja,testing compiler:c++17-lang localbase:ldflags # cmake refuses to work with ninja
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	openfheorg
GH_PROJECT=	openfhe-development
GH_TUPLE=	openfheorg:cereal:984e3f1:cereal/third-party/cereal \
		google:googletest:8b4817e:google_test/third-party/google-test

LDFLAGS+=	-pthread

CMAKE_OFF=	BUILD_UNITTESTS BUILD_EXAMPLES BUILD_BENCHMARKS
CMAKE_TESTING_ON=	BUILD_UNITTESTS
CMAKE_TESTING_TARGET=	testall

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		HEXL NTL OPENMP
OPTIONS_DEFAULT=	NTL

HEXL_DESC=		Buld with Intel hexl
HEXL_CMAKE_BOOL=	WITH_INTEL_HEXL
HEXL_BROKEN=		Fails to find hexl package and no hexl submodule

NTL_DESC=		Build with libntl
NTL_CMAKE_BOOL=		WITH_NTL
NTL_LIB_DEPENDS=	libgmp.so:math/gmp \
			libntl.so:math/ntl

OPENMP_CMAKE_BOOL=	WITH_OPENMP
.if exists(/usr/include/omp.h)
OPTIONS_DEFAULT+=	OPENMP
.else
OPENMP_BROKEN=		OpenMP isn't enabled on this architecture
.endif

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/openfhe/core/math/hal/intnat/ubintnat.h.orig

.include <bsd.port.mk>
