PORTNAME=	xtb
DISTVERSIONPREFIX=	v
DISTVERSION=	6.8.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Semiempirical Extended Tight-Binding Program Package
WWW=		https://github.com/grimme-lab/xtb

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib
BUILD_DEPENDS=	test-drive>0:devel/test-drive
TEST_DEPENDS=	test-drive>0:devel/test-drive

USES=		cmake:testing fortran blaslapack:openblas

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	WITH_TBLITE WITH_CPCMX

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

USE_LDCONFIG=	yes
FFLAGS+=	-std=legacy

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/CMakeLists.txt

# tests as of 6.8.0: 100% tests passed, 0 tests failed out of 47

.include <bsd.port.mk>
