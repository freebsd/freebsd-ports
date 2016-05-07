# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	taucs
PORTVERSION=	2.2
PORTREVISION=	13
CATEGORIES=	math
MASTER_SITES=	http://www.tau.ac.il/~stoledo/taucs/${PORTVERSION}/ \
		LOCAL/bf
DISTNAME=	${PORTNAME}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	C library of sparse linear solvers

LIB_DEPENDS=	libmetis.so:math/metis4

HAS_CONFIGURE=	yes
USES=		fortran tar:tgz
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

LDFLAGS+=	-L${LOCALBASE}/lib
LIBMETIS?=	-lmetis
MAKE_ENV+=	LIBBLAS="${BLAS}" LIBLAPACK="${LAPACK}" LIBMETIS="${LIBMETIS}"

BINS?=		direct iter taucs_run
TESTS ?=	complex stack timer linsolve memory

.if exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.elif ${WITH_BLAS} == reference
LIB_DEPENDS+=	liblapack.so:math/lapack
LIB_DEPENDS+=	libblas.so:math/blas
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/succedd/succeed/' \
		${WRKSRC}/progs/taucs_blas_underscore_test.c
	@${REINPLACE_CMD} -e 's/SUCCEDD/SUCCEED/' \
		${WRKSRC}/progs/test_linsolve.c

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ./configure)

post-configure:
	@${CP} -r ${WRKSRC} ${WRKSRC}_SHARED

archives: configure
	@${PRINTF} "\n\n%s\n\n\n" "Building libtaucs archives:"
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} lib/FreeBSD/libtaucs.a)
	(cd ${WRKSRC}_SHARED && ${SETENV} ${MAKE_ENV} PICFLAG="${PICFLAG}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} lib/FreeBSD/libtaucs.a)

lib: archives
	@${PRINTF} "\n\n%s\n\n\n" "Building shared library:"
	(cd ${WRKSRC}_SHARED/lib/FreeBSD && \
		${FC} ${FFLAGS} ${PICFLAG} ${LDFLAGS} -shared \
		-o libtaucs.so.1 -Wl,-x -Wl,-soname,libtaucs.so.1 \
		-Wl,--whole-archive libtaucs.a -Wl,--no-whole-archive)
	${STRIP_CMD} ${WRKSRC}_SHARED/lib/FreeBSD/libtaucs.so.1

bins: lib
	@${PRINTF} "\n\n%s\n\n\n" "Building (dynamically-linked) executables:"
#for the second pass through WRKSRC_SHARED, use a nonexistent MAKEOBJDIR to
#prevent make from entering the obj subdirectories and breaking the build (see,
#for example, the description of .OBJDIR in make(1)):
	(cd ${WRKSRC}_SHARED && \
		${SETENV} ${MAKE_ENV} MAKEOBJDIR="${NONEXISTENT}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${BINS:S|^|bin/FreeBSD/|})

do-build: bins

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD/libtaucs.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}_SHARED/lib/FreeBSD/libtaucs.so.1 \
		${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libtaucs.so.1 libtaucs.so)
	${INSTALL_DATA} ${WRKSRC}/build/FreeBSD/*.h \
		${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include
	(cd ${WRKSRC}_SHARED/bin/FreeBSD && \
		${INSTALL_PROGRAM} ${BINS} ${STAGEDIR}${PREFIX}/bin)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
.endif

check test: build
.for t in ${TESTS}
	@${PRINTF} "\n%s\n" "Building test_${t}"
	@cd ${WRKSRC}_SHARED ; ${FC} ${FFLAGS} -Llib/FreeBSD -L./ \
	${LDFLAGS} -o bin/FreeBSD/test_${t} \
	`${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} -V STDDEFS` \
	`${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} -V STDINCS` \
	progs/test_${t}.c -ltaucs ${LAPACK} ${BLAS} ${LIBMETIS}
	@${PRINTF} "\n%s\n\n\n" "Running test_${t}:"
	-@cd ${WRKSRC}_SHARED ; \
	${SETENV} LD_LIBRARY_PATH="lib/FreeBSD:/lib:/usr/lib:${LOCALBASE}/lib" \
	bin/FreeBSD/test_${t}
.endfor

#be conservative, and expose a regression test target for amd64 builds only, because
#some of the tests run amok during i386 tinderbox builds on amd64 hosts
.if ${ARCH} == "amd64"
regression-test: check
.endif

.include <bsd.port.mk>
