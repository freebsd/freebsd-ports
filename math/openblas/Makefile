PORTNAME=	openblas
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.30
PORTEPOCH=	2
CATEGORIES=	math
MASTER_SITES=	NL/lapack/timing/:lapack_tmg
DISTFILES=	large.tgz:lapack_tmg \
		timing.tgz:lapack_tmg
DIST_SUBDIR=	openblas

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Optimized BLAS library based on GotoBLAS2
WWW=		https://github.com/OpenMathLib/OpenBLAS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe fortran gmake perl5 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	OpenMathLib
GH_PROJECT=	OpenBLAS
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz
CPE_VENDOR=	openblas_project

USE_LDCONFIG=	yes
USE_PERL5=	build

OPENBLAS_SVER=	0
TEST_TARGET=	tests

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=			DYNAMIC_ARCH INTERFACE64 OPENMP
OPTIONS_DEFAULT=		OPENMP
OPTIONS_DEFINE_i386=		AVX AVX2 AVX512
OPTIONS_DEFINE_amd64=		AVX AVX2 AVX512
OPTIONS_EXCLUDE_armv6=		OPENMP
OPTIONS_EXCLUDE_armv7=		OPENMP
OPTIONS_EXCLUDE_powerpc64le=	OPENMP
OPTIONS_EXCLUDE_powerpc64=	OPENMP
OPTIONS_EXCLUDE_powerpc=	OPENMP
OPTIONS_RADIO=	${OPTIONS_RADIO_${ARCH}}
OPTIONS_RADIO_powerpc64=	POWER
OPTIONS_RADIO_POWER=	POWER6 POWER8
OPTIONS_SUB=	yes

.if defined(BATCH) || defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT_i386=	DYNAMIC_ARCH
OPTIONS_DEFAULT_amd64=	DYNAMIC_ARCH
OPTIONS_DEFAULT_powerpc64le=	DYNAMIC_ARCH
.endif

DYNAMIC_ARCH_DESC=	Optimize for multiple CPU types, otherwise for this CPU
INTERFACE64_DESC=	Use 8 byte integers on 64-bit architectures
OPENMP_DESC=		Use OpenMP for threading
AVX_DESC=		Support Advanced Vector Extensions (AVX)
AVX2_DESC=		Support Advanced Vector Extensions 2 (AVX2)
AVX512_DESC=		Support Advanced Vector Extensions 512 (AVX512)
POWER6_DESC=		Optimize for POWER6, instead of the default PPC970
POWER8_DESC=		Optimize for POWER8, instead of the default PPC970

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USE_GCC=		yes
.  if ${PORT_OPTIONS:MPOWER6}
TARGET_CPU_ARCH=	POWER6
.  elif ${PORT_OPTIONS:MPOWER8}
TARGET_CPU_ARCH=	POWER8
.else
TARGET_CPU_ARCH=	PPC970
.  endif
.endif

.if ${ARCH} == powerpc
USE_GCC=		yes
TARGET_CPU_ARCH=	PPCG4
.endif

.if ${ARCH} == powerpc64le
CFLAGS+=		-lm
USE_GCC=		yes
.endif

MAXTHREADS?=	64

.include <bsd.port.pre.mk>

post-extract:
	cd ${DISTDIR}/${DIST_SUBDIR} ; \
	${CP} ${LARGE_FILE} ${TIMING_FILE} ${WRKSRC}

post-patch:
	@${ECHO_CMD} MAKE_NB_JOBS=-1 >> ${WRKSRC}/Makefile.rule
	@${ECHO_CMD} NUM_THREADS=${MAXTHREADS} >> ${WRKSRC}/Makefile.rule
	@${ECHO_CMD} USE_THREAD=1 >> ${WRKSRC}/Makefile.rule
.if ! ${PORT_OPTIONS:MAVX}
	@${ECHO_CMD} NO_AVX=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ! ${PORT_OPTIONS:MAVX2}
	@${ECHO_CMD} NO_AVX2=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ! ${PORT_OPTIONS:MAVX512}
	@${ECHO_CMD} NO_AVX512=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ${PORT_OPTIONS:MDYNAMIC_ARCH}
	@${ECHO_CMD} DYNAMIC_ARCH=1 >> ${WRKSRC}/Makefile.rule
	@${ECHO_CMD} DYNAMIC_OLDER=1 >> ${WRKSRC}/Makefile.rule
.endif
.if defined(TARGET_CPU_ARCH)
	@${ECHO_CMD} TARGET=${TARGET_CPU_ARCH} >> ${WRKSRC}/Makefile.rule
.endif
.if ${PORT_OPTIONS:MINTERFACE64}
	@${ECHO_CMD} INTERFACE64=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ${PORT_OPTIONS:MOPENMP}
	@${ECHO_CMD} USE_OPENMP=1 >> ${WRKSRC}/Makefile.rule
.endif
.if ${ARCH:M*64*} == ""
	@${ECHO_CMD} BINARY=32 >> ${WRKSRC}/Makefile.rule
.else
	@${ECHO_CMD} BINARY=64 >> ${WRKSRC}/Makefile.rule
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

post-install-DYNAMIC_ARCH-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenblasp-r${PORTVERSION}.so

post-install-DYNAMIC_ARCH-off:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenblas_*p-r${PORTVERSION}.so
	cd ${STAGEDIR}${PREFIX} && ls lib/libopenblas_*p-r${PORTVERSION}.* >> ${TMPPLIST}

.include <bsd.port.post.mk>
