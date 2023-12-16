PORTNAME=	spheral
DISTVERSIONPREFIX=	v
DISTVERSION=	2023.06.0
PORTREVISION=	1
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Environment for hydrodynamical & gravitational numerical simulations
WWW=		https://github.com/LLNL/spheral

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/include/polyclipper2d.hh:math/polyclipper
LIB_DEPENDS=	libaxom.so:science/axom \
		libboost_filesystem.so:devel/boost-libs \
		libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libmfem.so:math/mfem \
		libosdCPU.so:graphics/opensubdiv \
		libpolytope.so:science/polytope \
		libqhull_r.so:math/qhull \
		libsiloh5.so:science/silo

USES=		cmake:testing compiler:c++14-lang eigen:3 fortran localbase:ldflags lua mpi:mpich python
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	llnl:blt:ddd5a0c:blt/cmake/blt \
		llnl:uberenv:126f8de:uberenv/scripts/devtools/uberenv

CMAKE_ARGS=	-Daneos_DIR=${LOCALBASE} \
		-Daxom_DIR=${LOCALBASE} \
		-Dboost_DIR=${LOCALBASE} \
		-Dconduit_DIR=${LOCALBASE} \
		-Deigen_DIR=${LOCALBASE} \
		-Dhdf5_DIR=${LOCALBASE} \
		-Dopensubdiv_DIR=${LOCALBASE} \
		-Dpython_DIR=${LOCALBASE} \
		-Dpolyclipper_DIR=${LOCALBASE} \
		-Dpolytope_DIR=${LOCALBASE} \
		-Dpybind11_DIR=${LOCALBASE} \
		-Dqhull_DIR=${LOCALBASE} \
		-Dsilo_DIR=${LOCALBASE} \
		-Dzlib_DIR=/usr
CMAKE_OFF=	ENABLE_TESTS ENABLE_DOCS \
		ENABLE_ANEOS \
		ENABLE_CUDA
CMAKE_ON=	ENABLE_CXXONLY # disable Python support which is still for Python-2.7, see https://github.com/LLNL/spheral/issues/183
CMAKE_ON+=	ENABLE_OPENMP
CMAKE_TESTING_ON=	ENABLE_TESTS # tests fail to build, see https://github.com/LLNL/spheral/issues/230

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3

BINARY_ALIAS=	git=false python=${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e 's|\.a|.so|; s|qhullstatic|qhull_r|; s|python2\.7|python${PYTHON_VER}|g' ${WRKSRC}/cmake/tpl/*.cmake
	@${CHMOD} +x ${WRKSRC}/src/helpers/InstantiationGenerator.py

post-install:
	# workaround for https://github.com/LLNL/spheral/issues/188
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake
	@${MV} ${STAGEDIR}${PREFIX}/Spheral/lib/cmake/* ${STAGEDIR}${PREFIX}/lib/cmake
	@${RM} -r ${STAGEDIR}${PREFIX}/Spheral

.include <bsd.port.mk>
