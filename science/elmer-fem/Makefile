# New ports collection makefile for:	elmer-fem
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fem
PORTVERSION=	5.4.0
PORTREVISION=	5
CATEGORIES=	science tk
MASTER_SITES=	# none known, please fix
PKGNAMEPREFIX=	elmer-

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	FEM solver for use in the ELMER FEM package

BUILD_DEPENDS=	${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		${LOCALBASE}/lib/libeiof.a:${PORTSDIR}/science/elmer-eio        \
		${LOCALBASE}/lib/libhuti.a:${PORTSDIR}/science/elmer-hutiter \
		${LOCALBASE}/lib/libumfpack_elmer.a:${PORTSDIR}/math/elmer-umfpack
RUN_DEPENDS=	ElmerGrid:${PORTSDIR}/science/elmergrid		\
		Mesh2D:${PORTSDIR}/science/elmer-meshgen2d

USE_FORTRAN=	yes

.ifdef WITH_OPTIMIZED_FLAGS
FCFLAGS+=	-O3 -ffast-math
.endif

USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=
USE_LDCONFIG=	yes
TEST_ENV=	ELMER_HOME=${PREFIX}

DATADIR=	${PREFIX}/share/elmersolver
PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FCFLAGS+=	-fPIC
FFLAGS+=	-fPIC ${FCFLAGS}
.endif
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	FCFLAGS="${FCFLAGS}"
CONFIGURE_ARGS+=	--with-umfpack="-lumfpack_elmer" \
			--with-blas="${BLAS}" \
			--with-lapack="${LAPACK}" \
			--with-eiof="-leiof" \
			--with-matc="-lmatc -lm"
pre-configure:
	${REINPLACE_CMD} -e 's|make|${GMAKE}|g' ${WRKSRC}/tests/runtests.in

.if defined(MAINTAINER_MODE)
regression-test:	install
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${TEST_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)
.endif

.include <bsd.port.post.mk>
