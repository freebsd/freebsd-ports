PORTNAME=	openmc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Monte Carlo neutron and photon transport simulation code
WWW=		https://openmc.org/ \
		https://docs.openmc.org/en/stable/ \
		https://github.com/openmc-dev/openmc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		compilation fails with clang-19, see https://github.com/openmc-dev/openmc/issues/3183

BUILD_DEPENDS=	xtensor>0:math/xtensor
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libpng16.so:graphics/png \
		libpugixml.so:textproc/pugixml

USES=		cmake:noninja,testing eigen:3 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-dev
GH_TUPLE=	catchorg:Catch2:5a40b22:catch2/vendor/Catch2 \
		martinmoene:gsl-lite:913e86d:gsl_lite/vendor/gsl-lite # gsl-lite isn't ported yet

CMAKE_OFF=	OPENMC_BUILD_TESTS
CMAKE_TESTING_ON=	OPENMC_BUILD_TESTS # tests are broken, see https://github.com/openmc-dev/openmc/issues/2449

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		LIBMESH MPI OPENMP
OPTIONS_DEFAULT=	MPI

LIBMESH_DESC=		Support for libMesh unstructured mesh tallies
LIBMESH_CMAKE_BOOL=	OPENMC_USE_LIBMESH
LIBMESH_LIB_DEPENDS=	libmesh_opt.so:math/libmesh

MPI_VARS=		CXX=${LOCALBASE}/bin/mpic++ # compilation breaks with OpenMPI-{3,4} and LIBMESH=ON
MPI_BUILD_DEPENDS=	mpich>0:net/mpich
MPI_RUN_DEPENDS=	mpich>0:net/mpich

OPENMP_CMAKE_BOOL=	OPENMC_USE_OPENMP

.if exists(/usr/include/omp.h)
OPTIONS_DEFAULT+=	OPENMP
.endif

post-install:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
