# $FreeBSD$

PORTNAME=	erkale
DISTVERSION=	g20181121
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry program to solve the electronic structure of atoms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	liberkale_omp.so.0.1.0: undefined reference to `__atomic_compare_exchange'

BUILD_DEPENDS=	armadillo>0:math/armadillo
LIB_DEPENDS=	libderiv.so:science/libint \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libint.so:science/libint \
		libopenblas.so:math/openblas \
		libsz.so:science/szip \
		libxc.so:science/libxc

FLAVORS=	serial parallel
FLAVOR?=	${FLAVORS:[1]}
serial_PKGNAMESUFFIX=	-serial

USES=		cmake:outsource,noninja fortran pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_TAGNAME=	0927d8c
USE_LDCONFIG=	yes

TEST_TARGET=	test

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	SUFFIX="${SUFFIX}"

.if ${FLAVOR} == serial
CMAKE_OFF=	USE_OPENMP
.else # parallel
CMAKE_ON+=	USE_OPENMP
LIB_DEPENDS+=	libomp.so:devel/openmp
SUFFIX=		_omp
.endif

OPTIONS_SINGLE=		LINALG
OPTIONS_SINGLE_LINALG=	NETLIB OPENBLAS
OPTIONS_DEFAULT=	NETLIB
LINALG_DESC=		Linear algebra library

NETLIB_USES=		blaslapack:netlib
NETLIB_CMAKE_ON=	-DLAPACK_LIBRARIES:STRING=-llapack -DBLAS_LIBRARIES:STRING=-lblas
NETLIB_LDFLAGS=		${LOCALBASE}/lib/libcblas.so ${LOCALBASE}/lib/liblapack.so ${LOCALBASE}/lib/libblas.so
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas

OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CMAKE_ON=	-DLAPACK_LIBRARIES:STRING=-lopenblas -DBLAS_LIBRARIES:STRING=-lopenblasp
xOPENBLAS_BROKEN=	hits the number of threads limit: https://github.com/xianyi/OpenBLAS/issues/1882

# use clang from ports because cmake can't find OpenMP with base clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
# have the same compiler for both serial and parallel flavors so that performance numbers can be compared
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

.if ${FLAVOR} == parallel
post-install:
	@${MV} ${STAGEDIR}${PREFIX}/include/erkale ${STAGEDIR}${PREFIX}/include/erkale${SUFFIX}
	@${MV} ${STAGEDIR}${PREFIX}/bin/erkale_bastool ${STAGEDIR}${PREFIX}/bin/erkale_bastool${SUFFIX}
.endif

.include <bsd.port.mk>
