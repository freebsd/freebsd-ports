# $FreeBSD$

PORTNAME=	liggghts
DISTVERSION=	3.8.0
PORTREVISION=	5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Discrete element method particle simulation software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libmpi.so:net/openmpi \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtkViewsCore-8.1.so:math/vtk8

USES=		compiler:c++17-lang cmake fortran jpeg qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	CFDEMproject
GH_PROJECT=	${PORTNAME:tu}-PUBLIC
USE_XORG=	ice sm x11 xext xt
USE_QT=		core gui sql widgets qmake_build buildtools_build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DMPI_C_COMPILER:FILEPATH="${LOCALBASE}/mpi/openmpi/bin/mpicc" -DMPI_CXX_COMPILER:FILEPATH="${LOCALBASE}/mpi/openmpi/bin/mpicxx" \
		-DVTK_DIR:FILEPATH="${LOCALBASE}/lib/cmake/vtk-8.1"

WRKSRC_SUBDIR=	src

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

BINARY_ALIAS=	sed=gsed

.include <bsd.port.mk>
