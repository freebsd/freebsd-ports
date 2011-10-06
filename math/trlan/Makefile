# New ports collection makefile for:	trlan
# Date created: 	5 Oct 2011
# Whom: 	b.f. <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trlan
PORTVERSION=	201009
CATEGORIES=	math
MASTER_SITES=	https://codeforge.lbl.gov/frs/download.php/210/:1 \
		http://crd.lbl.gov/~kewu/ps/:2 \
		LOCAL/bf:1,2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1 trlan-ug.pdf:2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Thick-restart Lanczos method for eigenproblems

USE_FORTRAN=	yes
USE_LDCONFIG=	yes

ALL_TARGET=	lib

PLIST_FILES=	lib/libtrlan.a lib/libtrlan.so lib/libtrlan.so.1

.include <bsd.port.pre.mk>

.ifndef(NOPORTDOCS)
PORTDOCS=	trlan-ug.pdf
.endif

.ifndef(NOPORTEXAMPLES)
PORTEXAMPLES=	Makefile README dense.f90 simple.f90 simple77.f simplec.c
.endif

.if ${ARCH} == sparc64
PICFLAG=	-fPIC
.else
PICFLAG=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e '/^(FC|FFLAGS)=/s/^/#/' \
		-e '/^F90=/s/=.*/=${FC}/' \
		${WRKSRC}/Make.inc
	@${REINPLACE_CMD} -E \
		-e '/^(CC|CFLAGS|LDFLAGS|TRLAN)=/s/^/#/' \
		${WRKSRC}/examples/SUN/Makefile
	@${REINPLACE_CMD} \
		-e 's|ar -cru|${AR} -cru|' \
		${WRKSRC}/SRC/Makefile

do-build:
	@${ECHO_CMD} "Building static archive ..."
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
		${ALL_TARGET}
	@${STRIP_CMD} -x -o ${WRKDIR}/libtrlan.a ${WRKSRC}/libtrlan.a
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
		clean
	@${ECHO_CMD} "Building shared library ..."
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
		${ALL_TARGET} FFLAGS="${PICFLAG} ${FFLAGS}"
	@${FC} ${FFLAGS} ${LDFLAGS} -shared -Wl,-x  -Wl,-soname,libtrlan.so.1 \
		-o ${WRKDIR}/libtrlan.so.1 -Wl,--whole-archive \
		${WRKSRC}/libtrlan.a -Wl,--no-whole-archive -Wl,--as-needed

do-install:
	@${INSTALL_DATA} ${WRKDIR}/libtrlan.* ${PREFIX}/lib
	@${LN} -sf libtrlan.so.1 ${PREFIX}/lib/libtrlan.so
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${DOCSDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/SUN && ${INSTALL_DATA} ${PORTEXAMPLES} \
	${EXAMPLESDIR}
.endif

.if defined(MAINTAINER_MODE)

BUILD_DEPENDS +=	${LOCALBASE}/lib/libblas.so.2:${PORTSDIR}/math/blas \
			${LOCALBASE}/lib/liblapack.so.4:${PORTSDIR}/math/lapack

BLAS?=		-L${LOCALBASE}/lib -lblas
LAPACK?=	-L${LOCALBASE}/lib -llapack

check regression-test test: test-static test-shared

test-static: build
	@${ECHO_CMD} "Checking static archive ..."
	@cd ${WRKSRC}/examples/SUN; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
		${MAKE_ARGS} clean simple simple77 simplec \
		LDFLAGS="${LDFLAGS} ${LAPACK} ${BLAS}" \
		TRLAN="${WRKDIR}/libtrlan.a" ; \
		./simple ; ./simple77 ; ./simplec

test-shared: build
	@${ECHO_CMD} "Checking shared library ..."
	@cd ${WRKSRC}/examples/SUN; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
		${MAKE_ARGS} clean simple simple77 simplec \
		FFLAGS="${PICFLAG} ${FFLAGS}" \
		LDFLAGS="${LDFLAGS} ${LAPACK} ${BLAS}" \
		TRLAN="-L${WRKDIR} -ltrlan" ; \
		./simple ; ./simple77 ; ./simplec

.endif

.include <bsd.port.post.mk>
