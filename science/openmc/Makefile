PORTNAME=	openmc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Monte Carlo neutron and photon transport simulation code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xtensor>0:math/xtensor
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libpugixml.so:textproc/pugixml \
		libsz.so:science/szip

USES=		cmake:noninja eigen:3 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-dev
GH_TUPLE=	martinmoene:gsl-lite:913e86d:gsl_lite/vendor/gsl-lite

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		LIBMESH MPI OPENMP
OPTIONS_DEFAULT=	MPI OPENMP

LIBMESH_DESC=		Support for libMesh unstructured mesh tallies
LIBMESH_CMAKE_BOOL=	libmesh
LIBMESH_LIB_DEPENDS=	libmesh_opt.so:math/libmesh
LIBMESH_BROKEN=		https://github.com/openmc-dev/openmc/issues/1893

MPI_VARS=		CXX=${LOCALBASE}/mpi/openmpi/bin/mpic++
MPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
MPI_RUN_DEPENDS=	openmpi>0:net/openmpi

OPENMP_CMAKE_BOOL=	openmp

post-install:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
