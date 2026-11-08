PORTNAME=	erkale
DISTVERSION=	g20260930
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry program to solve the electronic structure of atoms
WWW=		https://github.com/susilehtola/erkale

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	liberkale_omp.so.0.1.0: undefined reference to `__atomic_compare_exchange'

BUILD_DEPENDS=	armadillo>0:math/armadillo \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libcint.so:science/libcint \
		libgmp.so:math/gmp \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libmpfr.so:math/mpfr \
		libwignernj.so:science/libwignernj \
		libxc.so:science/libxc
RUN_DEPENDS=	${LOCALBASE}/share/erkale/basis/6-21G.gbs:science/erkale-pseudopotentials

FLAVORS=	parallel serial
FLAVOR?=	${FLAVORS:[1]}
serial_PKGNAMESUFFIX=	-serial

USES=		cmake:noninja compiler:c++17-lang fortran pkgconfig
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17 # upstream requires C++17 (std::sph_bessel, etc.)

USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_TAGNAME=	62c0f53

TEST_TARGET=	test

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DERKALE_SYSTEM_LIBRARY=${DATADIR}/basis

CMAKE_OFF=	ERKALE_BUILD_NEO \
		ERKALE_FETCH_TREXIO

PLIST_SUB=	SUFFIX="${SUFFIX}"

.if ${FLAVOR} == serial
CMAKE_OFF+=	USE_OPENMP
.else # parallel
CMAKE_ON+=	USE_OPENMP
SUFFIX=		_omp
.  if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.  endif
.endif

OPTIONS_SINGLE=		LINALG
OPTIONS_SINGLE_LINALG=	NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS
LINALG_DESC=		Linear algebra library

NETLIB_USES=		blaslapack:netlib
NETLIB_CMAKE_ON=	-DLAPACK_LIBRARIES:STRING=-llapack -DBLAS_LIBRARIES:STRING=-lblas
NETLIB_LDFLAGS=		${LOCALBASE}/lib/libcblas.so ${LOCALBASE}/lib/liblapack.so ${LOCALBASE}/lib/libblas.so
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
NETLIB_BROKEN=		choosing NETLIB causes a conflict: openblas-0.3.7_3,1 conflicts with cblas-1.0_12 on /usr/local/include/cblas.h

OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CMAKE_ON=	-DLAPACK_LIBRARIES:STRING=-lopenblas -DBLAS_LIBRARIES:STRING=-lopenblas

.if ${FLAVOR} == parallel
post-install:
	@if [ -d ${STAGEDIR}${PREFIX}/include/erkale ]; then \
		${MV} ${STAGEDIR}${PREFIX}/include/erkale ${STAGEDIR}${PREFIX}/include/erkale${SUFFIX}; \
	fi
	@if [ -e ${STAGEDIR}${PREFIX}/bin/erkale_bastool ]; then \
		${MV} ${STAGEDIR}${PREFIX}/bin/erkale_bastool ${STAGEDIR}${PREFIX}/bin/erkale_bastool${SUFFIX}; \
	fi
.endif

# tests as of g20260930: 100% tests passed, 0 tests failed out of 184

.include <bsd.port.mk>
