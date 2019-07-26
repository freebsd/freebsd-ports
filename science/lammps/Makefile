# $FreeBSD$

PORTNAME=	lammps
PORTVERSION=	${GH_TAGNAME:C/(stable|patch)_([0-9]{1,2})([A-Z][a-z][a-z])([0-9]{4})/\4.\3.\2/S/Jan/01/S/Feb/02/S/Mar/03/S/Apr/04/S/May/05/S/Jun/06/S/Jul/07/S/Aug/08/S/Sep/09/S/Oct/10/S/Nov/11/S/Dec/12/}
CATEGORIES=	science

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	e8d891c0ddb78c5be220fb9ccdcdbba1fa24509f.patch:-p1 \
		0bb9df76c2d132e66e79f482432ac2f33ec9781e.patch:-p1 # fix of potentials and frc folder installation: https://github.com/lammps/lammps/pull/1588

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical molecular dynamics code with a focus on materials modeling

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'
CONFLICTS_BUILD=	ga # conflicts with include/error.h, already fixed in the head

USES=		blaslapack:openblas cmake:noninja eigen:3 fortran localbase:ldflags shebangfix
USE_GITHUB=	yes
GH_TAGNAME=	patch_19Jul2019
SHEBANG_GLOB=	*.sh *.bash
SHEBANG_FILES=	lib/kokkos/bin/nvcc_wrapper

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS"

OPTIONS_DEFINE=		JPEG PNG GZIP FFMPEG VORONOI LATTE
OPTIONS_GROUP=		PARALLEL
OPTIONS_GROUP_PARALLEL=	MPI OPENMP
OPTIONS_DEFAULT=	MPI OPENMP JPEG PNG GZIP FFMPEG VORONOI LATTE
PARALLEL_DESC=		Enable parallelizations:

MPI_CMAKE_BOOL=		BUILD_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi

OPENMP_USES=		localbase
OPENMP_CMAKE_BOOL=	BUILD_OMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

FFMPEG_BUILD_DEPENDS=	ffmpeg:multimedia/ffmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

JPEG_CMAKE_BOOL=	WITH_JPEG
JPEG_USES=		jpeg

PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png

GZIP_CMAKE_BOOL=	WITH_GZIP

FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

VORONOI_DESC=		Use voro++, Voronoi tessellation package
VORONOI_CMAKE_BOOL=	PKG_VORONOI
VORONOI_LIB_DEPENDS=	libvoro++.so:science/voro++

LATTE_DESC=		Use LATTE package
LATTE_CMAKE_BOOL=	PKG_LATTE
LATTE_LIB_DEPENDS=	liblatte.so:science/latte

PORTSCOUT=	ignore # due to a special version tagging scheme that this project uses portscout fails to find new versions, watching their GitHub release page instead

post-patch:
	@${REINPLACE_CMD} 's|SHELL = /bin/bash|SHELL = ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/Makefile

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} 's|find_program(FFMPEG_EXECUTABLE|#&|' ${WRKSRC}/cmake/CMakeLists.txt

.include <bsd.port.mk>
