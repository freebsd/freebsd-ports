# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abinit
DISTVERSION=	8.10.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://www.abinit.org/sites/default/files/packages/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full-featured atomic-scale first-principles simulation software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
BROKEN_i386=	Type mismatch in argument 'block_displ', see https://github.com/abinit/abinit/issues/19

LIB_DEPENDS=	liblapack.so:math/lapack \
		libblas.so:math/blas
RUN_DEPENDS=	atompaw:science/atompaw

USES=		fortran gmake localbase:ldflags
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CC_LDFLAGS="${LDFLAGS}" CXX_LDFLAGS="${LDFLAGS}" FC_LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-shared --disable-static
FCFLAGS+=	-ffree-line-length-none

OPTIONS_DEFINE=			OPENMP MPI
OPTIONS_DEFAULT=		OPENMP MPI

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LDFLAGS=			${LOCALBASE}/lib/libomp.so
OPENMP_LIB_DEPENDS=		libomp.so:devel/openmp

MPI_CONFIGURE_ENABLE=		mpi
MPI_VARS=			FFLAGS+=-I${LOCALBASE}/include FCFLAGS+=-I${LOCALBASE}/include
MPI_LDFLAGS=			${LOCALBASE}/lib/libmpich.so ${LOCALBASE}/lib/libmpicxx.so ${LOCALBASE}/lib/libmpifort.so
MPI_LIB_DEPENDS=		libmpi.so:net/mpich

do-test:
	@cd ${WRKSRC}/tests && ./configure && ${GMAKE} check

.include <bsd.port.mk>
