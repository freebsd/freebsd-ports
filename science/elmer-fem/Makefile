# New ports collection makefile for:	elmer-fem
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fem
PORTVERSION=	5.2.0
PORTREVISION=	1
CATEGORIES=	science tk84
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FEM solver for use in the ELMER FEM package

BUILD_DEPENDS=	${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		${LOCALBASE}/lib/libeiof.a:${PORTSDIR}/science/elmer-eio	\
		${LOCALBASE}/lib/libhuti.a:${PORTSDIR}/science/elmer-hutiter
RUN_DEPENDS=	ElmerGrid:${PORTSDIR}/science/elmergrid		\
		Mesh2D:${PORTSDIR}/science/elmer-meshgen2d
LIB_DEPENDS=	umfpack.1:${PORTSDIR}/math/suitesparse
.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
LAPACK=		-llapack
.endif

WANT_FORTRAN=   yes
USE_GCC=4.2+

.ifdef WITH_OPTIMIZED_FLAGS
FCFLAGS+=	-O3 -ffast-math
.endif

USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=
USE_LDCONFIG=	yes
TEST_ENV=	ELMER_HOME=${PREFIX}

DATADIR=	${PREFIX}/share/elmersolver
PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FCFLAGS+=	-fPIC
FFLAGS+=	-fPIC ${FCFLAGS}
.endif
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FCFLAGS="${FCFLAGS}"

pre-configure:
	${REINPLACE_CMD} -e 's|make|${GMAKE}|g' ${WRKSRC}/tests/runtests.in

.if defined(MAINTAINER_MODE)
regression-test:	install
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${TEST_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)
.endif

.include <bsd.port.post.mk>
