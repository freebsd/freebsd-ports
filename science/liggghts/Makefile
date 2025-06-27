PORTNAME=	liggghts
DISTVERSION=	3.8.0-58
PORTREVISION=	7
DISTVERSIONSUFFIX=	-g6e28cfe3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Discrete element method particle simulation software
WWW=		https://www.cfdem.com/liggghts-open-source-discrete-element-method-particle-simulation-code

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libhdf5_hl.so:science/hdf5 \
		libmpi.so:net/mpich \
		libnetcdf.so:science/netcdf \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtkViewsCore-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		compiler:c++17-lang cmake fortran gl jpeg python qt:5 xorg
USE_XORG=	ice sm x11 xext xt
USE_QT=		core declarative gui network opengl sql widgets qmake:build buildtools:build
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	CFDEMproject
GH_PROJECT=	${PORTNAME:tu}-PUBLIC

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-${VTK_VER} \
		-DPython3_EXECUTABLE=${PYTHON_CMD}

WRKSRC_SUBDIR=	src

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC \
		-I${LOCALBASE}/include/vtk-${VTK_VER}

BINARY_ALIAS=	sed=gsed

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
