PORTNAME=	bout++
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.2
PORTREVISION=	5
CATEGORIES=	science math # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plasma fluid finite-difference simulation code
WWW=		https://boutproject.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libopenblas.so:math/openblas \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing python gettext-runtime shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	boutproject
GH_PROJECT=	BOUT-dev
GH_TUPLE=	boutproject:boutdata:3a66e6c:boutdata/externalpackages/boutdata \
		boutproject:boututils:a79a00a:boututils/externalpackages/boututils \
		google:googletest:96f4ce0:googletest/externalpackages/googletest \
		meitar:git-archive-all.sh:fc86194:git_archive_all_sh/externalpackages/git-archive-all.sh \
		mpark:variant:0b488da:variant/externalpackages/mpark.variant

SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	bin/bout-boutdata-restart-create \
		bin/bout-pylib-cmd-to-bin \
		bin/bout-sonnet \
		bin/bout-stop-script \
		bin/bout_3to4.py \
		bin/bout_4to5

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BOUT_TESTS
CMAKE_TESTING_ON=	BOUT_TESTS # tests fail to build, see https://github.com/boutproject/BOUT-dev/issues/2618

CXXFLAGS+=	-I${WRKSRC}/include
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		OPENMP PETSC SLEPC SUNDIALS
OPTIONS_MULTI=		FORMAT
OPTIONS_MULTI_FORMAT=	HDF5 NETCDF
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH NETCDF # PETSC SLEPC: not compatible with the latest petsc-3.18.4

FORMAT_DESC=		File format support

HDF5_CMAKE_BOOL=	BOUT_USE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5

NETCDF_USES=		localbase:ldflags pkgconfig # because of the cmake patch in files/
NETCDF_CMAKE_BOOL=	BOUT_USE_NETCDF
NETCDF_LIB_DEPENDS=	libnetcdf_c++4.so:science/netcdf-cxx \
			libnetcdf.so:science/netcdf

MPICH_USES=		mpi:mpich

OPENMP_CMAKE_BOOL=	BOUT_ENABLE_OPENMP
OPRNMP_BROKEN=		SEGV when OpenMP is enabled, see https://github.com/boutproject/BOUT-dev/issues/2620

OPENMPI_USES=		mpi:openmpi

PETSC_DESC=		Build with PETSc support
PETSC_CMAKE_BOOL=	BOUT_USE_PETSC
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc

SLEPC_DESC=		Build with SLEPc support
SLEPC_CMAKE_BOOL=	BOUT_USE_SLEPC
SLEPC_LIB_DEPENDS=	libslepc.so:math/slepc
SLEPC_IMPLIES=		PETSC # build breaks w/out petsc

SUNDIALS_DESC=		Build with Sundials support
SUNDIALS_CMAKE_BOOL=	BOUT_USE_SUNDIALS
SUNDIALS_CMAKE_ON=	-DBOUT_DOWNLOAD_SUNDIALS=OFF
SUNDIALS_BROKEN=	fails to build with sundials, see https://github.com/boutproject/BOUT-dev/issues/2617

BINARY_ALIAS=		make=${GMAKE}

.if defined(WITH_EXAMPLES) # Build executables demonstrating BOUT++ capabilities. They aren't installed and don't need to be built for packaging.
CMAKE_ON+=	BOUT_BUILD_EXAMPLES
.endif

post-install:
	# workaround for /usr/local/lib/cmake/bout++/bout++Config.cmake:if
	@${REINPLACE_CMD} -i '' \
		-e 's|${BUILD_WRKSRC}/externalpackages/mpark.variant|${PREFIX}/lib/cmake/mpark_variant|' \
		-e 's|${BUILD_WRKSRC}/externalpackages/PVODE|${PREFIX}/lib/cmake/PVODE|' \
		-e 's|${WRKSRC}/cmake|${PREFIX}/lib/cmake/bout++|' \
		${STAGEDIR}${PREFIX}/lib/cmake/bout++/bout++Config.cmake
	# remove *.orig files created by patching
	@${RM} ${STAGEDIR}${PREFIX}/include/*.orig
	# install missing PVODE cmake files
	@${RM} ${STAGEDIR}${PREFIX}/lib/cmake/PVODE/*
	${INSTALL_DATA} ${BUILD_WRKSRC}/externalpackages/PVODE/PVODEConfig.cmake ${STAGEDIR}${PREFIX}/lib/cmake/PVODE
	${INSTALL_DATA} ${BUILD_WRKSRC}/externalpackages/PVODE/PVODEConfigVersion.cmake ${STAGEDIR}${PREFIX}/lib/cmake/PVODE
	@${REINPLACE_CMD} -i '' \
		-e 's|${BUILD_WRKSRC}/lib|${PREFIX}/lib|' \
		-e 's|${PORTSDIR}/.*/BOUT-dev-${PORTVERSION}/externalpackages/PVODE/include|${PREFIX}/include|g' \
		${STAGEDIR}${PREFIX}/lib/cmake/PVODE/*
	@${REINPLACE_CMD} -i '' \
		-e 's|INTERFACE_INCLUDE_DIRECTORIES .*|INTERFACE_INCLUDE_DIRECTORIES "${PREFIX}/include"|' \
		${STAGEDIR}${PREFIX}/lib/cmake/PVODE/PVODEConfig.cmake
	# remove broken link, see https://github.com/boutproject/BOUT-dev/issues/2623
	@${RM} ${STAGEDIR}${PREFIX}/bin/bout-squashoutput

.include <bsd.port.mk>
