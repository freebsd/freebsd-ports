# Ports collection makefile for: gotoblas
# Date created:         20070203
# Whom:			Sato Hiroki <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gotoblas
PORTVERSION=	2.${GOTOBLAS2VER}
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|maho/gotoblas|} \
		NL:lapack,lapack_tmg
MASTER_SITE_SUBDIR=	lapack/:lapack lapack/timing/:lapack_tmg
DISTFILES=	GotoBLAS2-${GOTOBLAS2VER}_bsd.tar.gz \
		lapack-3.1.1.tgz:lapack \
		large.tgz:lapack_tmg timing.tgz:lapack_tmg
EXTRACT_ONLY=	${GOTOBLAS2_SRCFILE}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A fast implementation of Basic Linear Algebra Subprograms

LICENSE=	BSD

DIST_SUBDIR=	gotoblas
GOTOBLAS2VER=	1.13
GOTOBLAS2_SRCFILE=	GotoBLAS2-${GOTOBLAS2VER}_bsd.tar.gz
LAPACK_SRCFILE=	lapack-3.1.1.tgz
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/GotoBLAS2

USE_PERL5_BUILD=	yes
USE_FORTRAN=	yes
GOTOLIBS=	libgoto2 libgoto2p
GOTOFILES=	${GOTOLIBS:S|$|.so|} ${GOTOLIBS:S|$|.so.1|} ${GOTOLIBS:S|$|.a|}
PLIST_FILES=	${GOTOFILES:S|^|lib/|}
SUB_FILES=	pkg-message
SUB_LIST=	MAXTHREADS=${MAXTHREADS}

OPTIONS=	DYNAMIC_ARCH	"Support multiple CPU types on i386 and amd64" \
							${DYNAMIC_ARCH_DEFAULT} \
		INTERFACE64	"Use 8 byte integers on 64-bit architectures" off \
		OPENMP		"Use OpenMP for threading" off
#		QUAD_PRECISION	"Support IEEE quad precision (experimental)" off

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
DYNAMIC_ARCH_DEFAULT=	on
.else
DYNAMIC_ARCH_DEFAULT=	off
.endif

MAXTHREADS?=	8

.if ${ARCH:M*64} == ""
GOTOFLAGS+=	BINARY32=1
.else
GOTOFLAGS+=	BINARY64=1
.endif

.if defined(WITH_DYNAMIC_ARCH)
GOTOFLAGS+=	DYNAMIC_ARCH=1
.endif

.if defined(WITH_INTERFACE64)
GOTOFLAGS+=	INTERFACE64=1
.endif

.if defined(WITH_OPENMP)
GOTOFLAGS+=	USE_OPENMP=1
.endif

.if defined(WITH_QUAD_PRECISION)
BROKEN =	WITH_QUAD_PRECISION is broken; please disable this option
GOTOFLAGS+=	QUAD_PRECISION=1
.endif

post-extract:
	${FIND} ${WRKSRC} -type f -name '.*' -delete
	cd ${DISTDIR}/${DIST_SUBDIR} ; \
	${CP} ${LAPACK_SRCFILE} ${LARGE_FILE} ${TIMING_FILE} ${WRKSRC}
	${MKDIR} ${WRKDIR}/lib

post-patch:
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
		${WRKSRC}/reference/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" \
	-e 's+%%LOCALBASE%%+${LOCALBASE}+' \
	-e 's+%%_GCC_BUILD_DEPENDS%%+${_GCC_BUILD_DEPENDS}+' \
	-e 's+$$(CROSS_SUFFIX)+${LOCALBASE}/bin/+' \
		${WRKSRC}/Makefile.system
.if defined(WITH_OPENMP)
	${REINPLACE_CMD} -e "s+GOTO_NUM_THREADS+OMP_NUM_THREADS+g" \
		${WRKSRC}/test/Makefile \
		${WRKSRC}/ctest/Makefile
.endif

do-build:
	cd ${WRKSRC} ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=1 USE_THREAD=0 \
	${GMAKE} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libgoto2.a ${WRKDIR}/lib/libgoto2.a
	${CP} ${WRKSRC}/libgoto2.so ${WRKDIR}/lib/libgoto2.so.1
	cd ${WRKSRC} ; ${GMAKE} ${MAKE_ARGS} clean
	cd ${WRKSRC} ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${GMAKE} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libgoto2.a ${WRKDIR}/lib/libgoto2p.a
	${CP} ${WRKSRC}/libgoto2.so ${WRKDIR}/lib/libgoto2p.so.1
.if !defined(WITH_DEBUG)
	${LOCALBASE}/bin/strip -X ${WRKDIR}/lib/*.so.1
.endif

BENCHMARK_MAXTHREADS?=	${MAXTHREADS}
.if defined(WITH_OPENMP)
BENCHMARK_THREADS_FLAG =	OMP_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.else
BENCHMARK_THREADS_FLAG =	GOTO_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.endif

benchmark: build
	cd ${WRKSRC} ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${GMAKE} ${MAKE_ARGS} hpl
	cd ${WRKSRC}/benchmark ; ${SETENV} ${GOTOFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${BENCHMARK_THREADS_FLAG} ${GMAKE} ${MAKE_ARGS}

do-install:
	cd ${WRKDIR}/lib ; \
	${INSTALL_DATA} ${GOTOLIBS:S|$|.a|} ${GOTOLIBS:S|$|.so.1|} \
	${PREFIX}/lib/
	cd ${PREFIX}/lib ; \
	for i in ${GOTOLIBS:S|$|.so|}; do \
		${LN} -sf $$i.1 $$i ; \
	done

.include <bsd.port.post.mk>
