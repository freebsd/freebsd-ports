# Created by: Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
# $FreeBSD$

PORTNAME=	openblas
PORTVERSION=	0.2.20
PORTREVISION=	1
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	NL/lapack/timing/:lapack_tmg
DISTFILES=	large.tgz:lapack_tmg timing.tgz:lapack_tmg
DIST_SUBDIR=	openblas

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Optimized BLAS library based on GotoBLAS2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fortran gmake perl5

USE_GITHUB=	yes
GH_ACCOUNT=	xianyi
GH_PROJECT=	OpenBLAS
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz

USE_LDCONFIG=	yes
USE_PERL5=	build

OPENBLAS_SUFX=	r${PORTVERSION}
OPENBLAS_LIBS=	libopenblas libopenblasp
OPENBLAS_SVER=	0
OPENBLAS_FILES=	${OPENBLAS_LIBS:S|$|.so|} ${OPENBLAS_LIBS:S|$|.so.${OPENBLAS_SVER}|} ${OPENBLAS_LIBS:S|$|.a|}
PLIST_FILES=	${OPENBLAS_FILES:S|^|lib/|}
TEST_TARGET=	tests

OPTIONS_DEFINE=		INTERFACE64 OPENMP
OPTIONS_DEFINE_i386=	DYNAMIC_ARCH AVX AVX2
OPTIONS_DEFINE_amd64=	${OPTIONS_DEFINE_i386}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT_i386=	DYNAMIC_ARCH
OPTIONS_DEFAULT_amd64=	DYNAMIC_ARCH
.endif

DYNAMIC_ARCH_DESC=	Support multiple CPU types on i386 and amd64
INTERFACE64_DESC=	Use 8 byte integers on 64-bit architectures
OPENMP_DESC=		Use OpenMP for threading
AVX_DESC=		Support Advanced Vector Extensions (AVX)
AVX2_DESC=		Support Advanced Vector Extensions 2 (AVX2)

.include <bsd.port.options.mk>

.if defined(TARGET_CPU_ARCH)
BUILDFLAGS+=	TARGET=${TARGET_CPU_ARCH}
.endif

MAXTHREADS?=	8
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
.endif

.if ${PORT_OPTIONS:MINTERFACE64}
BUILDFLAGS+=	INTERFACE64=1
.endif

.if ${PORT_OPTIONS:MOPENMP}
USES+=		compiler:openmp
BUILDFLAGS_THREAD+=	USE_OPENMP=1
.endif

.if ! ${PORT_OPTIONS:MAVX}
BUILDFLAGS+=	NO_AVX=1
.endif

.if ! ${PORT_OPTIONS:MAVX2}
BUILDFLAGS+=	NO_AVX2=1
.endif

post-extract:
	cd ${DISTDIR}/${DIST_SUBDIR} ; \
	${CP} ${LARGE_FILE} ${TIMING_FILE} ${WRKSRC}
	${MKDIR} ${WRKDIR}/lib

post-patch:
	${REINPLACE_CMD} -e "s+%%FIND%%+${FIND}+" \
	-e "s+%%XARGS%%+${XARGS}+" \
	-e "s+%%REINPLACE_CMD%%+${REINPLACE_CMD}+" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s+%%FC%%+${FC}+" -e "s+%%CC%%+${CC}+" \
		${WRKSRC}/Makefile.rule
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" \
		${WRKSRC}/Makefile.rule \
		${WRKSRC}/Makefile.tail \
		${WRKSRC}/driver/level3/Makefile \
		${WRKSRC}/driver/others/Makefile \
		${WRKSRC}/exports/Makefile \
		${WRKSRC}/interface/Makefile \
		${WRKSRC}/kernel/Makefile \
		${WRKSRC}/kernel/Makefile.L3 \
		${WRKSRC}/lapack/laswp/Makefile \
		${WRKSRC}/lapack-netlib/SRC/Makefile \
		${WRKSRC}/lapack-netlib/SRC/VARIANTS/Makefile \
		${WRKSRC}/lapack-netlib/TESTING/MATGEN/Makefile \
		${WRKSRC}/lapack-netlib/LAPACKE/src/Makefile \
		${WRKSRC}/lapack-netlib/LAPACKE/utils/Makefile \
		${WRKSRC}/reference/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" \
	-e 's+%%LDFLAGS%%+${LDFLAGS}+' \
	-e 's+%%LOCALBASE%%+${LOCALBASE}+' \
	-e 's+%%FIND%%+${FIND}+' \
	-e 's+%%XARGS%%+${XARGS}+' \
	-e 's+%%REINPLACE_CMD%%+${REINPLACE_CMD}+' \
	-e 's+$${CROSS_SUFFIX}+${LOCALBASE}/bin/+' \
	-e '/Clang.*OpenMP/g' \
		${WRKSRC}/Makefile.system

post-patch-OPENMP-on:
	${REINPLACE_CMD} -e "s+OPENBLAS_NUM_THREADS+OMP_NUM_THREADS+g" \
		${WRKSRC}/test/Makefile \
		${WRKSRC}/ctest/Makefile

do-build:
	cd ${WRKSRC} ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=1 USE_THREAD=0 \
	${MAKE_CMD} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libopenblas-${OPENBLAS_SUFX}.a ${WRKDIR}/lib/libopenblas.a
	${CP} ${WRKSRC}/libopenblas-${OPENBLAS_SUFX}.so ${WRKDIR}/lib/libopenblas.so.${OPENBLAS_SVER}
	cd ${WRKSRC} ; ${MAKE_CMD} ${MAKE_ARGS} clean
	cd ${WRKSRC} ; ${SETENV} ${BUILDFLAGS} ${BUILDFLAGS_THREAD} \
	${MAKE_CMD} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libopenblasp-${OPENBLAS_SUFX}.a ${WRKDIR}/lib/libopenblasp.a
	${CP} ${WRKSRC}/libopenblasp-${OPENBLAS_SUFX}.so ${WRKDIR}/lib/libopenblasp.so.${OPENBLAS_SVER}

BENCHMARK_MAXTHREADS?=	${MAXTHREADS}
.if ${PORT_OPTIONS:MOPENMP}
BENCHMARK_THREADS_FLAG=		OMP_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.else
BENCHMARK_THREADS_FLAG=		OPENBLAS_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.endif

benchmark: build
	cd ${WRKSRC} ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${MAKE_CMD} ${MAKE_ARGS} hpl
	cd ${WRKSRC}/benchmark ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${BENCHMARK_THREADS_FLAG} ${MAKE_CMD} ${MAKE_ARGS}

do-install:
.for L in ${OPENBLAS_LIBS}
	${INSTALL_DATA} ${WRKDIR}/lib/${L}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/lib/${L}.so.${OPENBLAS_SVER} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${L}.so.${OPENBLAS_SVER} ${STAGEDIR}${PREFIX}/lib/${L}.so
.endfor

.include <bsd.port.mk>
