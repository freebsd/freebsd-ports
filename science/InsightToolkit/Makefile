# Created by: bacon@smithers.neuro.mcw.edu
# $FreeBSD$

PORTNAME=	InsightToolkit
PORTVERSION=	4.13.0
PORTREVISION=	1
CATEGORIES=	science biology
MASTER_SITES=	SF/itk/itk/${ITK_VER}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Insight Toolkit

LICENSE=	APACHE20

BUILD_DEPENDS=	googletest>=0:devel/googletest
LIB_DEPENDS=	libgdcmCommon.so:devel/gdcm \
		libexpat.so:textproc/expat2 \
		libfftw.so:math/fftw \
		libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libsz.so:science/szip \
		libtiff.so:graphics/tiff

USES=		cmake:outsource jpeg
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DITK_USE_KWSTYLE:BOOL=OFF \
		-DITK_USE_SYSTEM_LIBRARIES:BOOL=ON \
		-DITK_USE_SYSTEM_EXPAT:BOOL=ON \
		-DITK_USE_SYSTEM_FFTW:BOOL=ON \
		-DITK_USE_SYSTEM_GDCM:BOOL=ON \
		-DITK_USE_SYSTEM_HDF5:BOOL=ON \
		-DITK_USE_SYSTEM_JPEG:BOOL=ON \
		-DITK_USE_SYSTEM_PNG:BOOL=ON \
		-DITK_USE_SYSTEM_TIFF:BOOL=ON \
		-DITK_USE_SYSTEM_ZLIB:BOOL=ON
USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit
ITK_VER=	${PORTVERSION:R}
PLIST_SUB+=	ITK_VER=${ITK_VER}

OPTIONS_DEFINE=	EXAMPLES TESTING
EXAMPLES_DESC=	Build examples (very time consuming)
TESTING_DESC=	Build testing programs (very time consuming)

EXAMPLES_CMAKE_ON=	-DBUILD_EXAMPLES:BOOL=ON
TESTING_CMAKE_ON=	-DBUILD_TESTING:BOOL=ON

.include <bsd.port.mk>
