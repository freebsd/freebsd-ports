# $FreeBSD$

PORTNAME=	madness
DISTVERSION=	0.10.1.20180823
PORTREVISION=	5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiresolution adaptive numeric environment for scientific simulation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libsysinfo>0:devel/libsysinfo
LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich \
		libtbb.so:devel/tbb \
		libtcmalloc.so:devel/google-perftools \
		libxc.so:science/libxc

USES=		cmake:outsource compiler:c++14-lang fortran localbase:ldflags python:build
USE_GITHUB=	yes
GH_ACCOUNT=	m-a-d-n-e-s-s
GH_TAGNAME=	ebb3fd7
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLAPACK_LIBRARIES:STRING="-L${LOCALBASE}/lib -llapack -lblas -L${LOCALBASE}/lib/gcc${GCC_DEFAULT} -lgcc_s" -DPYTHON_EXECUTABLE=${PYTHON_CMD}

.include <bsd.port.mk>
