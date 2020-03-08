# $FreeBSD$

PORTNAME=	chrono
DISTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	science devel
PKGNAMESUFFIX=	-physics-simulation-engine

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for multi-physics simulation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	use of overloaded operator '[]' is ambiguous (with operand types 'chrono::quaternion' and 'int'): https://github.com/projectchrono/chrono/issues/158

BUILD_DEPENDS=	openmpi>0:net/openmpi

USES=		cmake compiler:c++14-lang eigen:3 fortran
USE_GITHUB=	yes
GH_ACCOUNT=	project${PORTNAME}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		HDF5 DEMOS PARALLEL TESTS
OPTIONS_DEFAULT=	HDF5 PARALLEL
OPTIONS_SUB=		yes

HDF5_CMAKE_BOOL=	ENABLE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5

DEMOS_DESC=		Build and install demo programs
DEMOS_CMAKE_BOOL=	BUILD_DEMOS

PARALLEL_DESC=		Enable parallelism
PARALLEL_CMAKE_BOOL=	ENABLE_MODULE_PARALLEL
PARALLEL_CMAKE_ON=	-DBLAZE_DIR:STRING=${LOCALBASE}/include
PARALLEL_BUILD_DEPENDS=	blaze>0:math/blaze \
			thrust>0:devel/thrust

TESTS_DESC=		Build and install unit test programs
TESTS_CMAKE_BOOL=	BUILD_TESTING

PORTSCOUT=	skipv:3.0.0 # their development continues under the branch 2.X. 3.0.0 should be ignored until they release a higher version

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-Wno-error=narrowing
.endif

post-extract:
	@${RM} ${WRKSRC}/data/opensim/Rajagopal2015.orig

post-patch:
	@${FIND} ${WRKSRC} -name CMakeLists.txt -o -name "*.cmake*" | ${XARGS} ${REINPLACE_CMD} -i '' 's|lib64|lib|'
	@${REINPLACE_CMD} -e 's/ -march=native//' \
		${WRKSRC}/cmake/FindAVX.cmake \
		${WRKSRC}/cmake/FindFMA.cmake \
		${WRKSRC}/cmake/FindSSE.cmake

post-stage: # https://github.com/projectchrono/chrono/issues/153
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/chrono_thirdparty/googlebenchmark ${STAGEDIR}${PREFIX}/include/chrono_thirdparty/googletest

.include <bsd.port.post.mk>
