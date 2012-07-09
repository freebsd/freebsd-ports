# New ports collection makefile for:	taucs
# Date created:		5 July 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	taucs
PORTVERSION=	2.2
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://www.tau.ac.il/~stoledo/taucs/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bf@FreeBSD.org
COMMENT=	C library of sparse linear solvers

LIB_DEPENDS=	metis.1:${PORTSDIR}/math/metis4

HAS_CONFIGURE=	yes
USE_FORTRAN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == atlas
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.elif ${WITH_BLAS} == reference
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

do-extract:
	@${MKDIR} ${WRKSRC}; cd ${WRKSRC}; ${EXTRACT_CMD} \
	${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
	${EXTRACT_AFTER_ARGS}

post-patch:
	@${CP} -r ${WRKSRC} ${WRKSRC}_SHARED

do-configure:
	@cd ${WRKSRC}; ./configure
	@cd ${WRKSRC}_SHARED; ./configure

post-configure:
	@cd ${WRKSRC}; ${PATCH} <${FILESDIR}/extra-patch-build-FreeBSD-makefile
	@cd ${WRKSRC}_SHARED; ${PATCH} <${FILESDIR}/extra-patch-build-FreeBSD-makefile
	@${REINPLACE_CMD} \
	-e 's+%%LOCALBASE%%+${LOCALBASE}+g;' -e 's+%%FC%%+${FC}+g;' \
	-e 's+%%BLAS%%+${BLAS}+g;' -e 's+%%LAPACK%%+${LAPACK}+g;' \
	-e 's+%%CC%%+${CC}+g;' -e 's+%%CFLAGS%%+${CFLAGS}+g;' \
	-e 's+%%FFLAGS%%+${FFLAGS}+g;' \
		${WRKSRC}/config/FreeBSD.mk
	@${REINPLACE_CMD} \
	-e 's+%%LOCALBASE%%+${LOCALBASE}+g;' -e 's+%%FC%%+${FC}+g;' \
	-e 's+%%BLAS%%+${BLAS}+g;' -e 's+%%LAPACK%%+${LAPACK}+g;' \
	-e 's+%%CC%%+${CC}+g;' -e 's+%%CFLAGS%%+${CFLAGS} ${PICFLAG}+g;' \
	-e 's+%%FFLAGS%%+${FFLAGS} ${PICFLAG}+g;' \
		${WRKSRC}_SHARED/config/FreeBSD.mk

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS}
	@cd ${WRKSRC}_SHARED; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS}
	cd ${WRKSRC}_SHARED/lib/FreeBSD ; ${FC} ${FFLAGS} ${PICFLAG} ${LDFLAGS} \
	-shared -o libtaucs.so.1 -Wl,-x -Wl,-soname,libtaucs.so.1 -Wl,--whole-archive \
	libtaucs.a -Wl,--no-whole-archive

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD/libtaucs.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}_SHARED/lib/FreeBSD/libtaucs.so.1 ${PREFIX}/lib
	@${LN} -sf libtaucs.so.1 ${PREFIX}/lib/libtaucs.so
	@${INSTALL_DATA} ${WRKSRC}/build/FreeBSD/*.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/src/*.h ${PREFIX}/include
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/direct ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/iter ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
