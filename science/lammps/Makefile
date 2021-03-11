# $FreeBSD$

PORTNAME=	lammps
PORTVERSION=	${GH_TAGNAME:C/(stable|patch)_([0-9]{1,2})([A-Z][a-z][a-z])([0-9]{4})/\4.\3.\2/S/Jan/01/S/Feb/02/S/Mar/03/S/Apr/04/S/May/05/S/Jun/06/S/Jul/07/S/Aug/08/S/Sep/09/S/Oct/10/S/Nov/11/S/Dec/12/}
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical molecular dynamics code with a focus on materials modeling

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'
CONFLICTS_BUILD=	ga mpich mpich2 # conflicts with include/error.h from ga, already fixed in the head

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		blaslapack:openblas cmake:noninja compiler:c++11-lang eigen:3 fortran localbase:ldflags shebangfix
USE_GITHUB=	yes
GH_TAGNAME=	patch_10Mar2021
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh *.bash
SHEBANG_FILES=	lib/kokkos/bin/nvcc_wrapper

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS" ${CMAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
CMAKE_ARGS_gcc=	-DBUILD_OMP:BOOL=false

# enable packages (for a complete list see STANDARD_PACKAGES in cmake/CMakeLists.txt)
CMAKE_ON+=	PKG_ASPHERE PKG_BODY PKG_CLASS2 PKG_COLLOID PKG_COMPRESS PKG_DIPOLE
CMAKE_ON+=	PKG_GRANULAR PKG_KSPACE PKG_MANYBODY PKG_MC PKG_MESSAGE PKG_MISC PKG_MOLECULE PKG_PERI PKG_POEMS PKG_QEQ
CMAKE_ON+=	PKG_REPLICA PKG_RIGID PKG_SHOCK PKG_SPIN PKG_SNAP PKG_SRD
CMAKE_ON+=	PKG_USER-ATC PKG_USER-AWPMD PKG_USER-BOCS PKG_USER-CGDNA PKG_USER-MESODPD PKG_USER-CGSDK PKG_USER-COLVARS
CMAKE_ON+=	PKG_USER-DIFFRACTION PKG_USER-DPD PKG_USER-DRUDE PKG_USER-EFF PKG_USER-FEP
CMAKE_ON+=	PKG_USER-MANIFOLD PKG_USER-MEAMC PKG_USER-MGPT PKG_USER-MISC PKG_USER-MOFFF PKG_USER-MOLFILE
CMAKE_ON+=	PKG_USER-PHONON PKG_USER-PTM PKG_USER-QTB PKG_USER-REACTION
CMAKE_ON+=	PKG_USER-REAXC PKG_USER-SDPD PKG_USER-SMD PKG_USER-SMTBQ PKG_USER-SPH PKG_USER-TALLY
CMAKE_ON+=	PKG_USER-UEF PKG_USER-QMMM PKG_USER-YAFF
# Packages requiring extra downloades or dependencies: PKG_MSCG PKG_USER-ADIOS2 PKG_USER-NETCDF PKG_USER-QUIP PKG_USER-SCAFACOS

OPTIONS_DEFINE=		EXCEPTIONS JPEG PNG GZIP FFMPEG
OPTIONS_GROUP=		PARALLEL PACKAGES
OPTIONS_DEFAULT=	EXCEPTIONS MPI OPENMP JPEG PNG GZIP FFMPEG H5MD KIM KOKKOS LATTE PLUMED VORONOI ${OPTIONS_DEFAULT_${CHOSEN_COMPILER_TYPE}}
OPTIONS_SUB=		yes
PARALLEL_DESC=		Enable parallelizations:
PACKAGES_DESC=		Enable packages:
OPTIONS_GROUP_PARALLEL=	MPI OPENMP ${OPTIONS_DEFINE_${CHOSEN_COMPILER_TYPE}}
OPTIONS_GROUP_PACKAGES=	H5MD KIM KOKKOS LATTE PLUMED VORONOI VTK

EXCEPTIONS_DESC=	Enable the use of C++ exceptions
EXCEPTIONS_CMAKE_BOOL=	LAMMPS_EXCEPTIONS

MPI_CMAKE_BOOL=		BUILD_MPI PKG_MPIIO PKG_USER-LB
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi
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

H5MD_DESC=		USER-H5MD package based on libhdf5
H5MD_CMAKE_BOOL=	PKG_USER-H5MD
H5MD_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/szip

KIM_DESC=		KIM package based on the OpenKim library/repository
KIM_USES=		pkgconfig
KIM_CMAKE_BOOL=		PKG_KIM
KIM_CMAKE_ON=		-DDOWNLOAD_KIM:BOOL=OFF
KIM_LIB_DEPENDS=	libkim-api.so:science/kim-api \
			libcurl.so:ftp/curl
KIM_RUN_DEPENDS=	openkim-models>0:science/openkim-models

KOKKOS_DESC=		kokkos package based on the libkokkos library
KOKKOS_CMAKE_BOOL=	PKG_KOKKOS EXTERNAL_KOKKOS
KOKKOS_LIB_DEPENDS=	libkokkoscore.so:devel/kokkos

LATTE_DESC=		latte package based on the liblatte library
LATTE_CMAKE_BOOL=	PKG_LATTE
LATTE_LIB_DEPENDS=	liblatte.so:science/latte

PLUMED_DESC=		plumed package based on the plumed library
PLUMED_USES=		pkgconfig
PLUMED_CMAKE_BOOL=	PKG_USER-PLUMED
PLUMED_CMAKE_ON=	-DPLUMED_MODE=shared
PLUMED_LIB_DEPENDS=	libplumed.so:science/plumed

VORONOI_DESC=		voro++, Voronoi tessellation package
VORONOI_CMAKE_BOOL=	PKG_VORONOI
VORONOI_LIB_DEPENDS=	libvoro++.so:science/voro++

VTK_DESC=		USER-VTK package based on the external vtk package
VTK_CMAKE_BOOL=		PKG_USER-VTK
VTK_CMAKE_ON=		-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2
VTK_USES=		qt:5 xorg
VTK_USE=		qt=core,gui,sql,widgets xorg=ice,sm,x11,xext,xt
VTK_LIB_DEPENDS=	libvtkImagingMath-8.2.so:math/vtk8 \
			libexpat.so:textproc/expat2 \
			libfreetype.so:print/freetype2 \
			libtiff.so:graphics/tiff

PORTSCOUT=	ignore:1 # due to a special version tagging scheme that this project uses portscout fails to find new versions, watching their GitHub release page instead

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DBUILD_OMP:BOOL=true
.endif

post-patch:
	@${REINPLACE_CMD} 's|SHELL = /bin/bash|SHELL = ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/Makefile

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} 's|find_program(FFMPEG_EXECUTABLE|#&|' ${WRKSRC}/cmake/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/python*

.include <bsd.port.mk>
