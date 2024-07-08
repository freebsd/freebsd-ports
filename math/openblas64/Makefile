PORTNAME=	openblas
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.27
CATEGORIES=	math
MASTER_SITES=	NL/lapack/timing/:lapack_tmg
PKGNAMESUFFIX=	64
DISTFILES=	large.tgz:lapack_tmg \
		timing.tgz:lapack_tmg
DIST_SUBDIR=	openblas

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenBLAS with 8 byte integers on 64-bits architectures
WWW=		https://github.com/OpenMathLib/OpenBLAS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Only for 64-bits architectures

USES=		cmake:testing compiler:c11 cpe fortran gmake pathfix pkgconfig
CMAKE_ARGS=	-DINTERFACE64:BOOL=on	\
		-DSUFFIX64_UNDERSCORE:STRING=64	\
		-DSYMBOLSUFFIX:STRING=_64	\
		-DBUILD_SHARED_LIBS:BOOL=on	\
		-DBUILD_STATIC_LIBS:BOOL=on	\
		-DUSE_THREAD:BOOL=on

USE_GITHUB=	yes
GH_ACCOUNT=	OpenMathLib
GH_PROJECT=	OpenBLAS
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz
CPE_VENDOR=	openblas_project

USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=			BENCHMARKS DYNAMIC_ARCH OPENMP
OPTIONS_DEFAULT=		OPENMP
OPTIONS_EXCLUDE_powerpc64le=	OPENMP
OPTIONS_EXCLUDE_powerpc64=	OPENMP
OPTIONS_SUB=	yes

.if defined(BATCH) || defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT_amd64=	DYNAMIC_ARCH
OPTIONS_DEFAULT_powerpc64le=	DYNAMIC_ARCH
.endif

BENCHMARKS_DESC=	Build the collection of BLAS/LAPACK benchmarks
DYNAMIC_ARCH_DESC=	Optimize for multiple CPU types, otherwise for this CPU

BENCHMARKS_CMAKE_BOOL=	BUILD_BENCHMARKS
DYNAMIC_ARCH_CMAKE_BOOL=DYNAMIC_ARCH DYNAMIC_OLDER
OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_LDFLAGS=		-lomp

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USE_GCC=		yes
.endif

.if ${ARCH} == powerpc64le
USE_GCC=		yes
.endif

post-extract:
	cd ${DISTDIR}/${DIST_SUBDIR} ; \
	${CP} ${LARGE_FILE} ${TIMING_FILE} ${WRKSRC}

pre-configure-OPENMP-on:
	${REINPLACE_CMD} -e "s+OPENBLAS_NUM_THREADS+OMP_NUM_THREADS+g" \
		${WRKSRC}/test/Makefile \
		${WRKSRC}/ctest/Makefile

.include <bsd.port.mk>
