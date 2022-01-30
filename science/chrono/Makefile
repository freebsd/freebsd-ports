PORTNAME=	chrono
DISTVERSION=	7.0.1
CATEGORIES=	science devel
PKGNAMESUFFIX=	-physics-simulation-engine

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	74df5c76d8d475818138a9a16ceccbd6f326247c.patch:-p1 # https://github.com/projectchrono/chrono/pull/295

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

ALL_MODULES=		Cascade Cosimulation Distributed FSI Irrlicht Multicore MUMPS OpenGL Pardiso_Project Postprocess Sensor SynChrono Vehicle
# module names in a human readable case; for the list of available modules: grep -r "option(ENABLE_MODULE" work

OPTIONS_DEFINE=			HDF5 DEMOS
OPTIONS_GROUP=			MODULES
OPTIONS_GROUP_MODULES=		${ALL_MODULES:tu}
MODULES_DESC=			Enable modules:
OPTIONS_DEFAULT=		HDF5
OPTIONS_SUB=			yes

HDF5_CMAKE_BOOL=		ENABLE_HDF5
HDF5_LIB_DEPENDS=		libhdf5.so:science/hdf5

DEMOS_DESC=			Build and install demo programs
DEMOS_CMAKE_BOOL=		BUILD_DEMOS
DEMOS_BROKEN=			/usr/local/lib/libdmumps.so: undefined reference to `mpi_pack_'

CASCADE_CMAKE_ON=		-DCASCADE_INCLUDE_DIR:STRING=${LOCALBASE}/include/OpenCASCADE -DCASCADE_LIBDIR:STRING=${LOCALBASE}/lib
CASCADE_LIB_DEPENDS=		libTKernel.so:cad/opencascade740

DISTRIBUTED_BROKEN=		requires cuda_runtime_api.h in thrust package which is missing for some reason
DISTRIBUTED_IMPLIES=		MULTICORE

FSI_BROKEN=			requires CUDA

IRRLICHT_LIB_DEPENDS=		libIrrlicht.so:x11-toolkits/irrlicht

MULTICORE_BUILD_DEPENDS=	blaze>0:math/blaze \
				thrust>0:devel/thrust

MUMPS_CMAKE_ON=			-DMUMPS_ROOT:STRING=${LOCALBASE}
MUMPS_LIB_DEPENDS=		libdmumps.so:math/mumps \
				libopenblas.so:math/openblas

PARDISO_PROJECT_BROKEN=		Not available for FreeBSD; License is restrictive

SENSOR_BROKEN=			requires CUDA

SYNCHRONO_USES=			localbase
SYNCHRONO_BUILD_DEPENDS=	flatbuffers>0:devel/flatbuffers
SYNCHRONO_LIB_DEPENDS=		libmpi.so:net/mpich
SYNCHRONO_IMPLIES=		VEHICLE

OPENGL_LIB_DEPENDS=		libglfw.so:graphics/glfw
OPENGL_BROKEN=			clang-12 crashes

VEHICLE_LIB_DEPENDS=		libsz.so:science/szip \
				libmpi.so:net/openmpi

.for module in ${ALL_MODULES}
${module:tu}_DESC=		Chrono ${module} module
${module:tu}_CMAKE_BOOL=	ENABLE_MODULE_${module:tu}
.if "${${module:tu}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${module:tu}
.endif
.endfor

#.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCASCADE} && ${PORT_OPTIONS:MIRRLICHT}
PLIST_FILES+=	include/chrono_cascade/ChIrrCascadeMeshTools.h
.endif

.if ${PORT_OPTIONS:MVEHICLE} && ${PORT_OPTIONS:MIRRLICHT}
PLIST_FILES+=	lib/libChronoEngine_vehicle_irrlicht.so
.endif

#.include <bsd.port.pre.mk>

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

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.post.mk>
