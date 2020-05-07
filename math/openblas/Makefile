# Created by: Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
# $FreeBSD$

PORTNAME=	openblas
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.9
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	NL/lapack/timing/:lapack_tmg
DISTFILES=	large.tgz:lapack_tmg \
		timing.tgz:lapack_tmg
DIST_SUBDIR=	openblas

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	ee2e758278b5d82b7242f505ea694f082ef65879.patch:-p1 # fixes the regression: https://github.com/xianyi/OpenBLAS/pull/2512

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Optimized BLAS library based on GotoBLAS2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fortran gmake perl5 pkgconfig

CONFLICTS_INSTALL=	cblas lapacke

USE_GITHUB=	yes
GH_ACCOUNT=	xianyi
GH_PROJECT=	OpenBLAS
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz

USE_LDCONFIG=	yes
USE_PERL5=	build

OPENBLAS_SVER=	0
TEST_TARGET=	tests

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=			DYNAMIC_ARCH INTERFACE64 OPENMP
OPTIONS_DEFAULT=		OPENMP
OPTIONS_DEFINE_i386=		AVX AVX2
OPTIONS_DEFINE_amd64=		AVX AVX2
OPTIONS_DEFINE_powerpc64=	POWER6
OPTIONS_EXCLUDE_powerpc64=	OPENMP
OPTIONS_SUB=	yes

.if defined(BATCH) || defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT_i386=	DYNAMIC_ARCH
OPTIONS_DEFAULT_amd64=	DYNAMIC_ARCH
.endif

DYNAMIC_ARCH_DESC=	Support multiple CPU types on i386 and amd64
INTERFACE64_DESC=	Use 8 byte integers on 64-bit architectures
OPENMP_DESC=		Use OpenMP for threading
AVX_DESC=		Support Advanced Vector Extensions (AVX)
AVX2_DESC=		Support Advanced Vector Extensions 2 (AVX2)
POWER6_DESC=		Optimize for POWER6, instead of the default PPC970

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USE_GCC=		yes
.  if ${PORT_OPTIONS:MPOWER6}
TARGET_CPU_ARCH=	POWER6
.else
TARGET_CPU_ARCH=	PPC970
.  endif
.endif

MAXTHREADS?=	64

.if ! ${PORT_OPTIONS:MDYNAMIC_ARCH} && ( ${ARCH} == "amd64" || ${ARCH} == "i386" )
MANUAL_PACKAGE_BUILD=	Optimizes for the build machine.
.endif

.if ${PORT_OPTIONS:MOPENMP}
USES+=		compiler:openmp
.else
USES+=		compiler:c11
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENMP}
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif
.endif

post-extract:
	cd ${DISTDIR}/${DIST_SUBDIR} ; \
	${CP} ${LARGE_FILE} ${TIMING_FILE} ${WRKSRC}

post-patch:
	@${ECHO} MAKE_NB_JOBS=-1 >> ${WRKSRC}/Makefile.rule
	@${ECHO} NUM_THREADS=${MAXTHREADS} >> ${WRKSRC}/Makefile.rule
	@${ECHO} USE_THREAD=1 >> ${WRKSRC}/Makefile.rule
.if ! ${PORT_OPTIONS:MAVX}
	@${ECHO} NO_AVX=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ! ${PORT_OPTIONS:MAVX2}
	@${ECHO} NO_AVX2=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ${PORT_OPTIONS:MDYNAMIC_ARCH}
	@${ECHO} DYNAMIC_ARCH=1 >> ${WRKSRC}/Makefile.rule
	@${ECHO} DYNAMIC_OLDER=1 >> ${WRKSRC}/Makefile.rule
.endif
.if defined(TARGET_CPU_ARCH)
	@${ECHO} TARGET=${TARGET_CPU_ARCH} >> ${WRKSRC}/Makefile.rule
.endif
.if ${PORT_OPTIONS:MINTERFACE64}
	@${ECHO} INTERFACE64=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ${PORT_OPTIONS:MOPENMP}
	@${ECHO} USE_OPENMP=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ${ARCH:M*64} == ""
	@${ECHO} BINARY=32 >> ${WRKSRC}/Makefile.rule
.else
	@${ECHO} BINARY=64 >> ${WRKSRC}/Makefile.rule
.endif

post-patch-OPENMP-on:
	@${REINPLACE_CMD} -e "s+OPENBLAS_NUM_THREADS+OMP_NUM_THREADS+g" \
		${WRKSRC}/test/Makefile \
		${WRKSRC}/ctest/Makefile

BENCHMARK_MAXTHREADS?=	${MAXTHREADS}
.if ${PORT_OPTIONS:MOPENMP}
BENCHMARK_THREADS_FLAG=	OMP_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.else
BENCHMARK_THREADS_FLAG=	OPENBLAS_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.endif

benchmark: build
	cd ${WRKSRC} ; ${SETENV} ${MAKE_CMD} ${MAKE_ARGS} hpl
	cd ${WRKSRC}/benchmark ; ${SETENV} ${BENCHMARK_THREADS_FLAG} ${MAKE_CMD} ${MAKE_ARGS}

post-install-DYNAMIC_ARCH-off:
	cd ${STAGEDIR}${PREFIX} && ls lib/libopenblas_*p-r${PORTVERSION}.* >> ${TMPPLIST}

.include <bsd.port.post.mk>
