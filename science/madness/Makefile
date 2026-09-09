PORTNAME=	madness
DISTVERSION=	2026.09.05 # upstream didn't make any releases for 11 years but keep making commits, so use the date for now (other distros do the same)
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiresolution adaptive numeric environment for scientific simulation
WWW=		https://github.com/m-a-d-n-e-s-s/madness

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		libsysinfo>0:devel/libsysinfo
LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libmctc-lib.so:science/mctc-lib \
		libmpi.so:net/mpich \
		libs-dftd3.so:science/simple-dftd3 \
		libxc.so:science/libxc
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++20-lang fortran localbase:ldflags python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	m-a-d-n-e-s-s
GH_TAGNAME=	0ea6e1a9e4fed5bb322b27ce638070b6c6361d1a

CMAKE_ARGS=	-DLAPACK_LIBRARIES:STRING="-L${LOCALBASE}/lib -llapack -lblas -L${LOCALBASE}/lib/gcc${GCC_DEFAULT} -lgcc_s" -DPYTHON_EXECUTABLE=${PYTHON_CMD}
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

OPTIONS_DEFINE=		TBB
#OPTIONS_DEFAULT=	TBB # oneTBB support needs to be fixed: https://github.com/m-a-d-n-e-s-s/madness/issues/366

TBB_DESC=		Enables use of Intel Thread Building Blocks
TBB_CMAKE_BOOL=		ENABLE_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb

.include <bsd.port.mk>
