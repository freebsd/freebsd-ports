PORTNAME=	lammps
PORTVERSION=	${GH_TAGNAME:C/(stable|patch)_([0-9]{1,2})([A-Z][a-z][a-z])([0-9]{4})/\4.\3.\2/S/Jan/01/S/Feb/02/S/Mar/03/S/Apr/04/S/May/05/S/Jun/06/S/Jul/07/S/Aug/08/S/Sep/09/S/Oct/10/S/Nov/11/S/Dec/12/S/_update/./:C/\.([1-9])$/.0\1/:S/.//g}
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical molecular dynamics code with a focus on materials modeling
WWW=		https://lammps.sandia.gov/ \
		https://github.com/lammps/lammps

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'

LIB_DEPENDS=	libevent.so:devel/libevent \
		libfftw3.so:math/fftw3 \
		libhwloc.so:devel/hwloc2 \
		libnghttp2.so:www/libnghttp2 \
		libpciaccess.so:devel/libpciaccess \
		libssh2.so:security/libssh2 \
		libzstd.so:archivers/zstd

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

USES=		blaslapack:openblas cmake:noninja,testing compiler:c++17-lang eigen:3 fortran gnome localbase:ldflags python shebangfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	cython

USE_GITHUB=	yes
GH_TAGNAME=	patch_19Nov2024

SHEBANG_GLOB=	*.sh *.bash
SHEBANG_FILES=	lib/kokkos/bin/nvcc_wrapper

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS" ${CMAKE_ARGS_${CHOSEN_COMPILER_TYPE}} \
		-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_ARGS_gcc=	-DBUILD_OMP:BOOL=false
CMAKE_TESTING_ON=	ENABLE_TESTING # 3 tests fail, see https://github.com/lammps/lammps/issues/3875

# enable packages (for a complete list see STANDARD_PACKAGES in cmake/CMakeLists.txt)
CMAKE_ON+=	${LAMMPS_STANDARD_PACKAGES:S/^/PKG_/} # LAMMPS_STANDARD_PACKAGES is defined in Makefile.packages
# Packages requiring extra downloades or dependencies: PKG_MSCG PKG_ADIOS PKG_MDI PKG_MESONT PKG_ML-PACE PKG_NETCDF PKG_ML-QUIP PKG_SCAFACOS PKG_VTK
# PKG_ML-HDNNP downloads https://github.com/CompPhysVienna/n2p2/archive/v2.1.4.tar.gz

OPTIONS_DEFINE=		EXCEPTIONS JPEG PNG GZIP FFMPEG
OPTIONS_GROUP=		PARALLEL PACKAGES
OPTIONS_DEFAULT=	EXCEPTIONS MPI OPENMP JPEG PNG GZIP FFMPEG H5MD KIM KOKKOS LATTE NETCDF PLUMED VORONOI ${OPTIONS_DEFAULT_${CHOSEN_COMPILER_TYPE}}
OPTIONS_SUB=		yes
PARALLEL_DESC=		Enable parallelizations:
PACKAGES_DESC=		Enable packages:
OPTIONS_GROUP_PARALLEL=	MPI OPENMP ${OPTIONS_DEFINE_${CHOSEN_COMPILER_TYPE}}
OPTIONS_GROUP_PACKAGES=	H5MD KIM KOKKOS LATTE NETCDF PLUMED VORONOI VTK

EXCEPTIONS_DESC=	Enable the use of C++ exceptions
EXCEPTIONS_CMAKE_BOOL=	LAMMPS_EXCEPTIONS

MPI_CMAKE_BOOL=		BUILD_MPI PKG_MPIIO
MPI_LIB_DEPENDS=	libmpi_cxx.so:net/openmpi4
MPI_USES=		compiler:c11

FFMPEG_CMAKE_BOOL=	WITH_FFMPEG
FFMPEG_BUILD_DEPENDS=	ffmpeg:multimedia/ffmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

JPEG_CMAKE_BOOL=	WITH_JPEG
JPEG_USES=		jpeg

PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png

GZIP_DESC=		Enable GZIP support
GZIP_CMAKE_BOOL=	WITH_GZIP

H5MD_DESC=		H5MD package based on the libhdf5 library
H5MD_CMAKE_BOOL=	PKG_H5MD
H5MD_LIB_DEPENDS=	libhdf5.so:science/hdf5

KIM_DESC=		KIM package based on the OpenKim library/repository
KIM_USES=		pkgconfig
KIM_CMAKE_BOOL=		PKG_KIM
KIM_CMAKE_ON=		-DDOWNLOAD_KIM:BOOL=OFF
KIM_LIB_DEPENDS=	libkim-api.so:science/kim-api \
			libcurl.so:ftp/curl
KIM_RUN_DEPENDS=	openkim-models>0:science/openkim-models

KOKKOS_DESC=		Kokkos package based on the libkokkos library
KOKKOS_CMAKE_BOOL=	PKG_KOKKOS EXTERNAL_KOKKOS
KOKKOS_LIB_DEPENDS=	libkokkoscore.so:devel/kokkos

LATTE_DESC=		Latte package based on the liblatte library
LATTE_CMAKE_BOOL=	PKG_LATTE
LATTE_LIB_DEPENDS=	liblatte.so:science/latte

NETCDF_DESC=		NetCDF package based on the NetCDF library
NETCDF_CMAKE_BOOL=	PKG_NETCDF
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf

PLUMED_DESC=		Plumed package based on the plumed library
PLUMED_USES=		pkgconfig
PLUMED_CMAKE_BOOL=	PKG_PLUMED
PLUMED_CMAKE_ON=	-DPLUMED_MODE=shared
PLUMED_LIB_DEPENDS=	libplumed.so:science/plumed

VORONOI_DESC=		Voro++, Voronoi tessellation package
VORONOI_CMAKE_BOOL=	PKG_VORONOI
VORONOI_LIB_DEPENDS=	libvoro++.so:science/voro++

VTK_DESC=		VTK package based on the external VTK-${VTK_VER:R} library
VTK_CMAKE_BOOL=		PKG_VTK
VTK_CMAKE_ON=		-DVTK_DIR:PATH=${LOCALBASE}/lib/cmake/vtk-${VTK_VER}
VTK_USES=		gl qt:5 xorg
VTK_USE=		GL=opengl qt=core,declarative,gui,network,opengl,sql,widgets xorg=ice,sm,x11,xext,xt
VTK_LIB_DEPENDS=	libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R} \
			libexpat.so:textproc/expat2 \
			libfreetype.so:print/freetype2 \
			libtiff.so:graphics/tiff

PORTSCOUT=	ignore:1 # due to a special version tagging scheme that this project uses portscout fails to find new versions, watching their GitHub release page instead

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DBUILD_OMP:BOOL=true
.endif

xpost-patch:
	# adjust SHELL in Makefile
	@${REINPLACE_CMD} 's|SHELL = /bin/bash|SHELL = ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/Makefile
	# fix python version, also see https://github.com/lammps/lammps/issues/3098, https://github.com/lammps/lammps/issues/3099
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" -o -name "*.cmake" | ${XARGS} ${REINPLACE_CMD} -e ' \
		s|find_package(Python3 REQUIRED |find_package(Python $${FREEBSD_PYTHON_VER} EXACT REQUIRED |; \
		s|find_package(Python 3.5 COMPONENTS |find_package(Python $${FREEBSD_PYTHON_VER} EXACT COMPONENTS |; \
		s|find_package(Python 3.6 COMPONENTS |find_package(Python $${FREEBSD_PYTHON_VER} EXACT COMPONENTS |; \
		s|find_package(Python3 REQUIRED |find_package(Python $${FREEBSD_PYTHON_VER} EXACT REQUIRED |; \
		s|find_package(Python COMPONENTS |find_package(Python3 $${FREEBSD_PYTHON_VER} EXACT COMPONENTS |; \
		s|find_package(Python3 COMPONENTS |find_package(Python3 $${FREEBSD_PYTHON_VER} EXACT COMPONENTS |; \
		s|find_package(Python QUIET COMPONENTS |find_package(Python3 $${FREEBSD_PYTHON_VER} EXACT QUIET COMPONENTS |; \
		s|find_package(Python REQUIRED COMPONENTS |find_package(Python3 $${FREEBSD_PYTHON_VER} EXACT REQUIRED COMPONENTS | \
		'

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} 's|find_program(FFMPEG_EXECUTABLE|#&|' ${WRKSRC}/cmake/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/python*

.include "Makefile.packages"
.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
