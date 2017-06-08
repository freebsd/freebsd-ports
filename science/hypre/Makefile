# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	hypre
DISTVERSION=	2.11.2
CATEGORIES=	science
MASTER_SITES=	https://computation.llnl.gov/projects/hypre-scalable-linear-solvers-multigrid-methods/download/

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Scalable Linear Solvers and Multigrid Methods

LICENSE=	LGPL21
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING.LESSER

USES=		blaslapack fortran localbase

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas --with-blas-lib=${BLASLIB} \
		--with-lapack --with-lapack-lib=${LAPACKLIB} \
		--enable-shared
CONFIGURE_ENV=	CC=mpicc CXX=mpicxx

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	MPI
OPTIONS_SINGLE_MPI=	MPICH2 OPENMPI
OPTIONS_DEFAULT=	MPICH2

MPICH2_LIB_DEPENDS=	libmpich.so.8:net/mpich2
OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi

.ifdef MAINTAINER_MODE
TEST_TARGET=	check
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/hypre/include/* ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/hypre/lib/libHYPRE-2.11.2.so	\
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so.2.11
	${RLN} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so.2.11 \
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so.2
	${RLN} ${STAGEDIR}${PREFIX}/lib/libHYPRE.so.2.11 \
		${STAGEDIR}${PREFIX}/lib/libHYPRE.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/*.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
