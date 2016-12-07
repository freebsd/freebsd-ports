# Created by: Sato Hiroki <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gotoblas
PORTVERSION=	2.${GOTOBLAS2VER}.${LAPACKVER}
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	LOCAL/maho/gotoblas \
		NL/lapack:lapack NL/lapack/timing:lapack_tmg
DISTFILES=	GotoBLAS2-${GOTOBLAS2VER}_bsd.tar.gz \
		lapack-${LAPACKVER}.tgz:lapack \
		large.tgz:lapack_tmg timing.tgz:lapack_tmg
DIST_SUBDIR=	gotoblas
EXTRACT_ONLY=	${GOTOBLAS2_SRCFILE}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Fast implementation of Basic Linear Algebra Subprograms

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/00License.txt

BROKEN_powerpc64=	Does not build

GOTOBLAS2VER=	1.13
GOTOBLAS2_SRCFILE=	GotoBLAS2-${GOTOBLAS2VER}_bsd.tar.gz
LAPACKVER=	3.4.0
LAPACK_SRCFILE=	lapack-${LAPACKVER}.tgz
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/GotoBLAS2

USES=		fortran gmake perl5
USE_GCC=	yes
USE_PERL5=	build
GOTOLIBS=	libgoto2 libgoto2p
GOTOFILES=	${GOTOLIBS:S|$|.so|} ${GOTOLIBS:S|$|.so.1|} ${GOTOLIBS:S|$|.a|}
PLIST_FILES=	${GOTOFILES:S|^|lib/|}
SUB_FILES=	pkg-message
SUB_LIST=	MAXTHREADS=${MAXTHREADS}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE_i386=	DYNAMIC_ARCH
OPTIONS_DEFINE_amd64=	DYNAMIC_ARCH
OPTIONS_DEFINE=	INTERFACE64 OPENMP

OPTIONS_DEFAULT_i386=	DYNAMIC_ARCH
OPTIONS_DEFAULT_amd64=	DYNAMIC_ARCH

DYNAMIC_ARCH_DESC=	Support multiple CPU types on i386 and amd64
INTERFACE64_DESC=	Use 8 byte integers on 64-bit architectures
OPENMP_DESC=		Use OpenMP for threading
#QUAD_PRECISION=	Support IEEE quad precision (experimental)

.include <bsd.port.options.mk>

MAXTHREADS?=	8

.if ${ARCH:M*64} == ""
GOTOFLAGS+=	BINARY32=1
.else
GOTOFLAGS+=	BINARY64=1
.endif

.if ${PORT_OPTIONS:MDYNAMIC_ARCH}
GOTOFLAGS+=	DYNAMIC_ARCH=1
.endif

.if ${PORT_OPTIONS:MINTERFACE64}
GOTOFLAGS+=	INTERFACE64=1
.endif

.if ${PORT_OPTIONS:MOPENMP}
GOTOFLAGS+=	USE_OPENMP=1
.endif

#.if ${PORT_OPTIONS:MQUAD_PRECISION}
#BROKEN=	WITH_QUAD_PRECISION is broken; please disable this option
#GOTOFLAGS+=	QUAD_PRECISION=1
#.endif

post-extract:
	${FIND} ${WRKSRC} -type f -name '.*' -delete
	cd ${DISTDIR}/${DIST_SUBDIR} ; \
	${CP} ${LAPACK_SRCFILE} ${LARGE_FILE} ${TIMING_FILE} ${WRKSRC}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib

post-patch:
	${REINPLACE_CMD} -e "s+%%FC%%+${FC}+" -e "s+%%CC%%+${CC}+" \
		${WRKSRC}/Makefile.rule
	${REINPLACE_CMD} -e "s+%%LAPACKVER%%+${LAPACKVER}+g" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s+%%LAPACKVER%%+${LAPACKVER}+g" \
		${WRKSRC}/exports/gensymbol
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
		${WRKSRC}/reference/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" \
	-e 's+%%_GCC_RUNTIME%%+${_GCC_RUNTIME}+' \
	-e 's+$$(CROSS_SUFFIX)+${LOCALBASE}/bin/+' \
		${WRKSRC}/Makefile.system

.if ${PORT_OPTIONS:MOPENMP}
	${REINPLACE_CMD} -e "s+GOTO_NUM_THREADS+OMP_NUM_THREADS+g" \
		${WRKSRC}/test/Makefile \
		${WRKSRC}/ctest/Makefile
.endif

do-build:
	cd ${WRKSRC} ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=1 USE_THREAD=0 \
	${MAKE_CMD} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libgoto2.a ${STAGEDIR}${PREFIX}/lib/libgoto2.a
	${CP} ${WRKSRC}/libgoto2.so ${STAGEDIR}${PREFIX}/lib/libgoto2.so.1
	cd ${WRKSRC} ; ${MAKE_CMD} ${MAKE_ARGS} clean
	cd ${WRKSRC} ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${MAKE_CMD} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libgoto2.a ${STAGEDIR}${PREFIX}/lib/libgoto2p.a
	${CP} ${WRKSRC}/libgoto2.so ${STAGEDIR}${PREFIX}/lib/libgoto2p.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.1

BENCHMARK_MAXTHREADS?=	${MAXTHREADS}
.if ${PORT_OPTIONS:MOPENMP}
BENCHMARK_THREADS_FLAG=		OMP_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.else
BENCHMARK_THREADS_FLAG=		GOTO_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.endif

benchmark: build
	cd ${WRKSRC} ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${MAKE_CMD} ${MAKE_ARGS} hpl
	cd ${WRKSRC}/benchmark ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${BENCHMARK_THREADS_FLAG} ${MAKE_CMD} ${MAKE_ARGS}

do-install:
	cd ${STAGEDIR}${PREFIX}/lib ; \
	${INSTALL_DATA} ${GOTOLIBS:S|$|.a|} ${GOTOLIBS:S|$|.so.1|} \
	${STAGEDIR}${PREFIX}/lib/
	cd ${STAGEDIR}${PREFIX}/lib ; \
	for i in ${GOTOLIBS:S|$|.so|}; do \
		${LN} -sf $$i.1 $$i ; \
	done

.include <bsd.port.mk>
