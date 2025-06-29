PORTNAME=	bout++
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.1
PORTREVISION=	2
CATEGORIES=	science math # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plasma fluid finite-difference simulation code
WWW=		https://boutproject.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfmt.so:devel/libfmt \
		libopenblas.so:math/openblas \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.2.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=8.1.0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>=0:science/py-netCDF4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.5.1:math/py-sympy@${PY_FLAVOR}

USES=		cmake:testing gettext python gettext-runtime shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	boutproject
GH_PROJECT=	BOUT-dev
GH_TUPLE=	google:googletest:0953a17a4281fc26831da647ad3fcd5e21e6473b:google_googletest/externalpackages/googletest \
		meitar:git-archive-all.sh:fc86194f00b678438f9210859597f6eead28e765:meitar_git_archive_all_sh/externalpackages/git-archive-all.sh \
		mpark:variant:23cb94f027d4ef33bf48133acc2695c7e5c6f1e7:mpark_variant/externalpackages/mpark.variant \
		boutproject:boutdata:e458cf0cf2af6ff68db91da39ef3e15a7e9e6b3d:boutproject_boutdata/externalpackages/boutdata \
		abseil:googletest:695cf7c96249de50360a7d2951dc88eb3aea0695:abseil_googletest/externalpackages/mpark.variant/3rdparty/googletest

SHEBANG_GLOB=	*.sh *.py
SHEBANG_FILES=	bin/bout-add-mod-path \
		bin/bout-boutdata-restart-create \
		bin/bout-pylib-cmd-to-bin \
		bin/bout-sonnet \
		bin/bout-stop-script \
		bin/bout_3to4.py \
		bin/bout_4to5

CMAKE_ON=	BUILD_SHARED_LIBS \
		BOUT_USE_SYSTEM_FMT
CMAKE_OFF=	BOUT_TESTS
CMAKE_TESTING_ON=	BOUT_TESTS

TESTING_UNSAFE=	6 tests fail, see https://github.com/boutproject/BOUT-dev/issues/2980

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

BINARY_ALIAS=		make=${GMAKE} \
			python3=${PYTHON_CMD}

.if defined(WITH_EXAMPLES) # Build executables demonstrating BOUT++ capabilities. They aren't installed and don't need to be built for packaging.
CMAKE_ON+=	BOUT_BUILD_EXAMPLES
.endif

post-patch:
	# fix the version number in the code that it can't obtain from git
	@${REINPLACE_CMD} \
		-e 's|__version__ = version(__name__)|__version__ = "${PORTVERSION}"|' \
		${WRKSRC}/tools/pylib/boutdata/__init__.py \
		${WRKSRC}/externalpackages/boutdata/src/boututils/__init__.py

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

pre-test: #  build tests
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_TESTING_ARGS} ${CMAKE_SOURCE_PATH} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${TEST_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} build-check

.include <bsd.port.mk>
