# Created by: Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
# $FreeBSD$

PORTNAME=	openblas
PORTVERSION=	0.3.7
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	NL/lapack/timing/:lapack_tmg
DISTFILES=	large.tgz:lapack_tmg \
		timing.tgz:lapack_tmg
DIST_SUBDIR=	openblas

PATCH_SITES=	https://github.com/xianyi/OpenBLAS/commit/
PATCHFILES=	3e67017ac8f0246f5fc14572ca663fb0968d1046.patch:-p1

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

BUILDFLAGS=	FCOMMON_OPT=-frecursive MAKE_NB_JOBS=-1

OPTIONS_DEFINE=			INTERFACE64 OPENMP
OPTIONS_DEFINE_i386=	AVX AVX2 DYNAMIC_ARCH
OPTIONS_DEFINE_amd64=	AVX AVX2 DYNAMIC_ARCH
OPTIONS_DEFINE_powerpc64=	POWER6
OPTIONS_EXCLUDE_powerpc64=	OPENMP

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

.if defined(TARGET_CPU_ARCH)
BUILDFLAGS+=	TARGET=${TARGET_CPU_ARCH}
MAKE_ENV+=	TARGET=${TARGET_CPU_ARCH}
.endif

MAXTHREADS?=		64
BUILDFLAGS_THREAD+=	NUM_THREADS=${MAXTHREADS} USE_THREAD=1

.if ${ARCH:M*64} == ""
BUILDFLAGS+=	BINARY32=1
.else
BUILDFLAGS+=	BINARY64=1
.endif

.if ! ${PORT_OPTIONS:MDYNAMIC_ARCH} && ( ${ARCH} == "amd64" || ${ARCH} == "i386" )
MANUAL_PACKAGE_BUILD=	Optimizes for the build machine.
.endif

.if ${PORT_OPTIONS:MDYNAMIC_ARCH}
BUILDFLAGS+=	DYNAMIC_ARCH=1
PLIST_SUB+=	DYNARCH=""
.else
PLIST_SUB+=	DYNARCH="@comment "
.endif

.if ${PORT_OPTIONS:MINTERFACE64}
BUILDFLAGS+=	INTERFACE64=1
.endif

.if ! ${PORT_OPTIONS:MAVX}
BUILDFLAGS+=	NO_AVX=1
.endif

.if ! ${PORT_OPTIONS:MAVX2}
BUILDFLAGS+=	NO_AVX2=1
.endif

.if ${PORT_OPTIONS:MOPENMP}
USES+=			compiler:openmp
BUILDFLAGS_THREAD+=	USE_OPENMP=1
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
	cd ${WRKSRC} ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${MAKE_CMD} ${MAKE_ARGS} hpl
	cd ${WRKSRC}/benchmark ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${BENCHMARK_THREADS_FLAG} ${MAKE_CMD} ${MAKE_ARGS}

post-install:
	cd ${WRKSRC} && \
		${FIND} . -name 'common*.h' -print | ${XARGS} ${BASENAME} | ${XARGS} -I {} ${MV} {} openblas_{}
	${MV} ${WRKSRC}/version.h ${WRKSRC}/openblas_version.h
	${MV} ${WRKSRC}/param.h ${WRKSRC}/openblas_param.h
	${MV} ${WRKSRC}/cpuid.h ${WRKSRC}/openblas_cpuid.h
	${MV} ${WRKSRC}/config.h ${WRKSRC}/openblas_config.h
	${REINPLACE_CMD} \
	-e 's/"common.h"/"openblas_common.h"/' \
	-e 's/"version.h"/"openblas_version.h"/' \
	-e 's/"param.h"/"openblas_param.h"/' \
	-e 's/"cpuid.h"/"openblas_cpuid.h"/' \
	-e 's/"config.h"/"openblas_config.h"/' \
	-e 's/"common_/"openblas_common_/' \
		${WRKSRC}/*.h \
		${WRKSRC}/*.c \
		${WRKSRC}/interface/*.c
	${MKDIR} ${STAGEDIR}${PREFIX}/include/openblas
	${INSTALL_DATA} ${WRKSRC}/openblas_*.h ${STAGEDIR}${PREFIX}/include/openblas
	${INSTALL_DATA} ${WRKSRC}/cblas.h ${WRKSRC}/config_last.h ${WRKSRC}/l1param.h ${WRKSRC}/l2param.h ${WRKSRC}/symcopy.h \
		${STAGEDIR}${PREFIX}/include/openblas
	${MV} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}_*-r${PORTVERSION}.a ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.a
	${MV} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}_*-r${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${OPENBLAS_SVER}
	${RM} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so
	${LN} -sf lib${PORTNAME}.so.${OPENBLAS_SVER} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.post.mk>
