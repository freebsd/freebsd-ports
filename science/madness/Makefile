PORTNAME=	madness
DISTVERSION=	0.10.1.20180823
PORTREVISION=	16
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiresolution adaptive numeric environment for scientific simulation
WWW=		https://github.com/m-a-d-n-e-s-s/madness

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libsysinfo>0:devel/libsysinfo
LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich \
		libtcmalloc.so:devel/google-perftools \
		libxc.so:science/libxc

USES=		cmake compiler:c++14-lang fortran localbase:ldflags python:build
USE_GITHUB=	yes
GH_ACCOUNT=	m-a-d-n-e-s-s
GH_TAGNAME=	ebb3fd7
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLAPACK_LIBRARIES:STRING="-L${LOCALBASE}/lib -llapack -lblas -L${LOCALBASE}/lib/gcc${GCC_DEFAULT} -lgcc_s" -DPYTHON_EXECUTABLE=${PYTHON_CMD}

OPTIONS_DEFINE=		TBB
#OPTIONS_DEFAULT=	TBB # oneTBB support needs to be fixed: https://github.com/m-a-d-n-e-s-s/madness/issues/366

TBB_DESC=		Enables use of Intel Thread Building Blocks
TBB_CMAKE_BOOL=		ENABLE_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb

.include <bsd.port.mk>
