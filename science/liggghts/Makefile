PORTNAME=	liggghts
DISTVERSION=	3.8.0-45
DISTVERSIONSUFFIX=	-g86544c3f
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Discrete element method particle simulation software

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
		libvtkViewsCore-9.1.so:math/vtk9

USES=		compiler:c++17-lang cmake fortran gl jpeg python qt:5 xorg
USE_XORG=	ice sm x11 xext xt
USE_QT=		core declarative gui network opengl sql widgets qmake_build buildtools_build
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	CFDEMproject
GH_PROJECT=	${PORTNAME:tu}-PUBLIC

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-9.1 \
		-DPython3_EXECUTABLE=${PYTHON_CMD}

WRKSRC_SUBDIR=	src

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC \
		-I${LOCALBASE}/include/vtk-9.1

BINARY_ALIAS=	sed=gsed

.include <bsd.port.mk>
