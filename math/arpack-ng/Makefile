# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arpack-ng
PORTVERSION=	3.1.5
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://forge.scilab.org/index.php/p/arpack-ng/downloads/get/ \
		LOCAL/bf
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT+=	Revised Argand library for solving large-scale eigenvalue problems

LICENSE=	BSD3CLAUSE

USES=		fortran libtool
USE_LDCONFIG=	yes

CONFLICTS=	arpack-[0-9]*
SLAVEDIRS=	math/arpack-ng-mpich

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-blas="${BLAS}" \
		--with-lapack="${LAPACK}"
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS MPI
OPTIONS_SUB=	yes
MPI_CONFIGURE_ENABLE=	mpi
MPI_LIB_DEPENDS=	libmpich.so.8:net/mpich2
MPI_CONFLICTS_INSTALL+=		arpack-ng-3.*
MPI_CONFLICTS_INSTALL_OFF+=	arpack-ng-mpich-3.*

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMPI}
PKGNAMESUFFIX=	-mpich
.endif

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
	${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/BLAS_LIBS.*LAPACK_LIBS/ \
	{s/LAPACK_LIBS/BLAS_LIBS/;s/BLAS_LIBS/LAPACK_LIBS/;}' \
	${WRKSRC}/Makefile.in \
	${WRKSRC}/arpack.pc.in \
	${WRKSRC}/TESTS/Makefile.in

post-build:
	@cd ${WRKSRC}/.libs; ${STRIP_CMD} libarpack.a libarpack.so.*.*

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

check regression-test test: build
	@cd ${WRKSRC}; ${DO_MAKE_BUILD} check

.include <bsd.port.post.mk>
