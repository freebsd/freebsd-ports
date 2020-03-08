# $FreeBSD$

PORTNAME=	erkale
DISTVERSION=	g20200110
PORTREVISION=	2
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
		libsz.so:science/szip \
		libxc.so:science/libxc
RUN_DEPENDS=	${LOCALBASE}/share/erkale/basis/6-21G.gbs:science/erkale-pseudopotentials

FLAVORS=	serial parallel
FLAVOR?=	${FLAVORS:[1]}
serial_PKGNAMESUFFIX=	-serial

USES=		cmake:noninja fortran pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_TAGNAME=	0d0c895b0d9bcbcb523e7d7c3a11f590d18827d2
USE_LDCONFIG=	yes

TEST_TARGET=	test

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DERKALE_SYSTEM_LIBRARY=${DATADIR}/basis

PLIST_SUB=	SUFFIX="${SUFFIX}"

.if ${FLAVOR} == serial
CMAKE_OFF=	USE_OPENMP
.else # parallel
CMAKE_ON+=	USE_OPENMP
SUFFIX=		_omp
.endif

OPTIONS_SINGLE=		LINALG
OPTIONS_SINGLE_LINALG=	NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS
LINALG_DESC=		Linear algebra library

NETLIB_USES=		blaslapack:netlib
NETLIB_CMAKE_ON=	-DLAPACK_LIBRARIES:STRING=-llapack -DBLAS_LIBRARIES:STRING=-lblas
NETLIB_LDFLAGS=		${LOCALBASE}/lib/libcblas.so ${LOCALBASE}/lib/liblapack.so ${LOCALBASE}/lib/libblas.so
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas

OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CMAKE_ON=	-DLAPACK_LIBRARIES:STRING=-lopenblas -DBLAS_LIBRARIES:STRING=-lopenblas
OPENBLAS_LIB_DEPENDS=	libopenblas.so:math/openblas

.if ${FLAVOR} == parallel
post-install:
	@${MV} ${STAGEDIR}${PREFIX}/include/erkale ${STAGEDIR}${PREFIX}/include/erkale${SUFFIX}
	@${MV} ${STAGEDIR}${PREFIX}/bin/erkale_bastool ${STAGEDIR}${PREFIX}/bin/erkale_bastool${SUFFIX}
.endif

.include <bsd.port.mk>
