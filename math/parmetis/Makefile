PORTNAME=	ParMetis
DISTVERSION=	4.0.3-p10
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	math parallel
MASTER_SITES=	https://bitbucket.org/petsc/pkg-parmetis/get/
DISTNAME=	${LGCOMMIT}
DIST_SUBDIR=	Metis

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Package for parallel (MPI) unstructured graph partitioning
WWW=		https://bitbucket.org/petsc/pkg-parmetis

LICENSE=	METIS
LICENSE_NAME=	University of Minnesota METIS License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept

BUILD_DEPENDS=	${NONEXISTENT}:math/metis:configure
LIB_DEPENDS=	libmetis.so:math/metis

USES=		cmake:insource,noninja gmake tar:bzip2
CONFIGURE_ENV=	MPI_HOME="${MPI_HOME}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENMPI STATIC
OPENMPI_DESC=	Use OpenMPI instead of MPICH
OPTIONS_SUB=	yes

OPENMPI_USES=			mpi:openmpi
OPENMPI_USES_OFF=		mpi

STATIC_DESC=			Do not build and install shared library
STATIC_VARS_OFF=		SH_FLAG="shared=1"

SHCOMMIT=	53c9341b6c1b
LGCOMMIT=	${SHCOMMIT}a876c97567cb52ddfc87c159dc36

WRKSRC=		${WRKDIR}/petsc-pkg-parmetis-${SHCOMMIT}
METIS_WRKSRC=	${MAKE} -C ${PORTSDIR}/math/metis -VWRKSRC

CFLAGS+=	-fPIC

.include <bsd.port.options.mk>

.if ((${ARCH}=="amd64") || (${ARCH}=="aarch64") || (${ARCH}=="ppc64"))
CFLAGS+=	-DMETIS_USE_LONGINDEX
.endif

pre-configure:
	@${MKDIR} ${WRKSRC}/metis
	${CP} -Rp "`${METIS_WRKSRC}`"/* ${WRKSRC}/metis
	${REINPLACE_CMD} -e \
		's|BUILDDIR =.*|BUILDDIR = build| ; \
		 s|make -C|$$(MAKE) -C| ; \
		 s|$$(MAKEFLAGS)||' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		's|"-O3"|""|' ${WRKSRC}/metis/GKlib/GKlibSystem.cmake
	${REINPLACE_CMD} -e \
		'/target_link_libraries(.* parmetis)/s/\(parmetis\)/& -lexecinfo/' \
		${WRKSRC}/programs/CMakeLists.txt

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} config prefix="${PREFIX}" cc="${MPICC}" cxx="${MPICXX}" ${SH_FLAG}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/parmetis
	${INSTALL_DATA} ${WRKSRC}/include/parmetis.h \
		${WRKSRC}/metis/include/metis.h \
		${STAGEDIR}${PREFIX}/include/parmetis
.if ${PORT_OPTIONS:MSTATIC}
	${INSTALL_DATA} ${WRKSRC}/build/libparmetis/libparmetis.a \
		${STAGEDIR}${PREFIX}/lib
.else
	${INSTALL_LIB} ${WRKSRC}/build/libparmetis/libparmetis.so \
		${STAGEDIR}${PREFIX}/lib/libparmetis.so.2
	cd ${STAGEDIR}${PREFIX}/lib &&	\
		${LN} -sf libparmetis.so.2 ${STAGEDIR}${PREFIX}/lib/libparmetis.so
.endif

.include <bsd.port.mk>
