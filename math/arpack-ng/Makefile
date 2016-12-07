# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arpack-ng
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Revised Argand library for solving large-scale eigenvalue problems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	opencollab

USES=		autoreconf:build fortran libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas="${BLAS}" \
		--with-lapack="${LAPACK}" \
		${MPICH_ARG}
MPICH_ARG?=	--disable-mpi
LDFLAGS+=	-L${LOCALBASE}/lib
TEST_TARGET=	check
USE_LDCONFIG=	yes

PORTEXAMPLES=	*

CONFLICTS=	arpack-[0-9]*
CONFLICTS_INSTALL?=	arpack-ng-mpich-3.*
SLAVEDIRS=	math/arpack-ng-mpich

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

WITH_BLAS?=	blas

.if ${WITH_BLAS} == "gotoblas"
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
LIB_DEPENDS+=	libgoto2p.so:math/gotoblas
.elif ${WITH_BLAS} == "atlas"
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
LIB_DEPENDS+=	libptf77blas.so:math/atlas
.elif ${WITH_BLAS} == "blas"
BLAS=		-lblas
LAPACK=		-llapack
LIB_DEPENDS+=	libblas.so:math/blas \
		liblapack.so:math/lapack
.else
IGNORE=		unknown value of WITH_BLAS: ${WITH_BLAS}
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|\(libdir\)(/pkgconfig)|(prefix)/libdata\1|' \
	${WRKSRC}/Makefile.am

pre-configure:
	@cd ${WRKSRC}; ./bootstrap
	@${REINPLACE_CMD} -e '/BLAS_LIBS.*LAPACK_LIBS/ \
	{s/LAPACK_LIBS/BLAS_LIBS/;s/BLAS_LIBS/LAPACK_LIBS/;}' \
	${WRKSRC}/Makefile.in \
	${WRKSRC}/arpack.pc.in \
	${WRKSRC}/TESTS/Makefile.in

post-build:
	@cd ${WRKSRC}/SRC/.libs; ${STRIP_CMD} libarpack.so.*.*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/EXAMPLES && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
