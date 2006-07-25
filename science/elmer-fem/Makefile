# New ports collection makefile for:	elmer-fem
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fem
PORTVERSION=	5.2.0
CATEGORIES=	science tk84
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FEM solver for use in the ELMER FEM package

BUILD_DEPENDS=	${FC}:${PORTSDIR}/lang/gfortran	\
		${LOCALBASE}/lib/libmatc.a:${PORTSDIR}/science/elmer-matc	\
		${LOCALBASE}/lib/libblas.a:${PORTSDIR}/math/elmer-mathlibs	\
		${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/elmer-mathlibs	\
		${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/elmer-umfpack	\
		${LOCALBASE}/lib/libeiof.a:${PORTSDIR}/science/elmer-eio	\
		${LOCALBASE}/lib/libhuti.a:${PORTSDIR}/science/elmer-hutiter
RUN_DEPENDS=	ElmerGrid:${PORTSDIR}/science/elmergrid		\
		Mesh2D:${PORTSDIR}/science/elmer-meshgen2d

USE_GCC=	4.1+
WITH_FORTRAN=	yes
FC=	${LOCALBASE}/bin/gfortran41
F77=	${FC}

.ifdef WITH_OPTIMIZED_FLAGS
FCFLAGS+=	-O3 -ffast-math
.endif

USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	FC=${FC} F77=${FC} FCFLAGS="${FCFLAGS}"
USE_GMAKE=	yes
ALL_TARGET=
INSTALLS_SHLIB=	yes
TEST_ENV=	ELMER_HOME=${PREFIX}

DATADIR=	${PREFIX}/share/elmersolver
PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FCFLAGS+=	-fPIC
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|make|${GMAKE}|g' ${WRKSRC}/tests/runtests.in

.if defined(MAINTAINER_MODE)
regression-test:	install
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${TEST_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)
.endif

.include <bsd.port.post.mk>
