# $FreeBSD$

PORTNAME=	lammps
PORTVERSION=	${GH_TAGNAME:C/(stable|patch)_([0-9]{1,2})([A-Z][a-z][a-z])([0-9]{4})/\4.\3.\2/S/Jan/01/S/Feb/02/S/Mar/03/S/Apr/04/S/May/05/S/Jun/06/S/Jul/07/S/Aug/08/S/Sep/09/S/Oct/10/S/Nov/11/S/Dec/12/}
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical molecular dynamics code with a focus on materials modeling

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'
CONFLICTS_BUILD=	ga # conflicts with include/error.h, already fixed in the head

USES=		blaslapack:openblas cmake:noninja eigen:3 fortran shebangfix
USE_GITHUB=	yes
GH_TAGNAME=	stable_12Dec2018
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

OPENMP_CMAKE_BOOL=	BUILD_OMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

FFMPEG_BUILD_DEPENDS=	ffmpeg:multimedia/ffmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

JPEG_CMAKE_BOOL=	WITH_JPEG
JPEG_USES=		jpeg

PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng16.so:graphics/png

GZIP_CMAKE_BOOL=	WITH_GZIP

FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

VORONOI_DESC=		Use voro++, Voronoi tessellation package
VORONOI_CMAKE_BOOL=	PKG_VORONOI
VORONOI_LIB_DEPENDS=	libvoro++.so:science/voro++

LATTE_DESC=		Use LATTE package
LATTE_CMAKE_BOOL=	PKG_LATTE
LATTE_LIB_DEPENDS=	liblatte.so:science/latte

# use clang from ports because cmake can't find OpenMP with base clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

post-patch:
	@${REINPLACE_CMD} 's|SHELL = /bin/bash|SHELL = ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/Makefile

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} 's|find_program(FFMPEG_EXECUTABLE|#&|' ${WRKSRC}/cmake/CMakeLists.txt

.include <bsd.port.mk>
