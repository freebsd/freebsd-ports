# Created by: bacon@smithers.neuro.mcw.edu
# $FreeBSD$

PORTNAME=	InsightToolkit
PORTVERSION=	4.9.1
CATEGORIES=	science biology
MASTER_SITES=	SF/itk/itk/4.9

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Insight Toolkit

LICENSE=	APACHE20

LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo \
		libgdcmCommon.so:devel/gdcm \
		libexpat.so:textproc/expat2 \
		libfftw.so:math/fftw \
		libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake:outsource
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

OPTIONS_DEFINE=	EXAMPLES TESTING
EXAMPLES_DESC=	Build examples (very time consuming)
TESTING_DESC=	Build testing programs (very time consuming)

EXAMPLES_CMAKE_ON=	-DBUILD_EXAMPLES:BOOL=ON
TESTING_CMAKE_ON=	-DBUILD_TESTING:BOOL=ON

.include <bsd.port.mk>
