# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	taucs
PORTVERSION=	2.2
PORTREVISION=	19
CATEGORIES=	math
MASTER_SITES=	http://www.tau.ac.il/~stoledo/taucs/${PORTVERSION}/ \
		LOCAL/bf
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library of sparse linear solvers

LICENSE=	TAUCS
LICENSE_NAME=	TAUCS License
LICENSE_FILE=	${FILESDIR}/TAUCS-license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libmetis.so:math/metis4

HAS_CONFIGURE=	yes
USES=		blaslapack fortran tar:tgz
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

LDFLAGS+=	-L${LOCALBASE}/lib
LIBMETIS?=	-lmetis
MAKE_ENV+=	LIBBLAS="${BLASLIB}" LIBLAPACK="${LAPACKLIB}" LIBMETIS="${LIBMETIS}"

BINS?=		direct iter taucs_run
TESTS?=		complex stack timer linsolve memory

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
		${FC} ${CFLAGS} ${PICFLAG} ${LDFLAGS} -shared \
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}

do-test: # XXX: building tests fail 
.for t in ${TESTS}
	@${PRINTF} "\n%s\n" "Building test_${t}"
	@cd ${WRKSRC}_SHARED ; ${FC} ${FFLAGS} -Llib/FreeBSD -L./ \
	${LDFLAGS} -o bin/FreeBSD/test_${t} \
	`${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} -V STDDEFS` \
	`${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} -V STDINCS` \
	progs/test_${t}.c -ltaucs ${LAPACKLIB} ${BLASLIB} ${LIBMETIS}
	@${PRINTF} "\n%s\n\n\n" "Running test_${t}:"
	-@cd ${WRKSRC}_SHARED ; \
	${SETENV} LD_LIBRARY_PATH="lib/FreeBSD:/lib:/usr/lib:${LOCALBASE}/lib" \
	bin/FreeBSD/test_${t}
.endfor

.include <bsd.port.mk>
