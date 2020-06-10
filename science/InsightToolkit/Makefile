# Created by: bacon@smithers.neuro.mcw.edu
# $FreeBSD$

PORTNAME=	InsightToolkit
PORTVERSION=	5.0.1
DISTVERSIONPREFIX=v
PORTREVISION=	5
CATEGORIES=	science biology
MASTER_SITES=	https://github.com/InsightSoftwareConsortium/ITK/releases/download/v5.0.1/:data
DISTFILES=	InsightData-5.0.1.tar.gz:data

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

USES=		cmake compiler:c++11-lang eigen:3 jpeg pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	InsightSoftwareConsortium
GH_PROJECT=	ITK
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DITK_FORBID_DOWNLOADS:BOOL=ON \
		-DITK_LEGACY_SILENT:BOOL=ON \
		-DITK_USE_KWSTYLE:BOOL=OFF \
		-DITK_USE_SYSTEM_EXPAT:BOOL=ON \
		-DITK_USE_SYSTEM_FFTW:BOOL=ON \
		-DITK_USE_SYSTEM_GDCM:BOOL=ON \
		-DITK_USE_SYSTEM_HDF5:BOOL=ON \
		-DITK_USE_SYSTEM_JPEG:BOOL=ON \
		-DITK_USE_SYSTEM_LIBRARIES:BOOL=ON \
		-DITK_USE_SYSTEM_PNG:BOOL=ON \
		-DITK_USE_SYSTEM_TIFF:BOOL=ON \
		-DITK_USE_SYSTEM_ZLIB:BOOL=ON \
		-DModule_ITKIOMIC:BOOL=ON \
		-DModule_ITKIOTransformMINC:BOOL=ON \
		-DModule_ITKReview:BOOL=ON
USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit
ITK_VER=	${PORTVERSION:R}
PLIST_SUB+=	ITK_VER=${ITK_VER}

OPTIONS_DEFINE=	EXAMPLES TESTING
EXAMPLES_DESC=	Build examples (very time consuming)
TESTING_DESC=	Build testing programs (very time consuming)

EXAMPLES_CMAKE_ON=	-DBUILD_EXAMPLES:BOOL=ON
TESTING_CMAKE_ON=	-DBUILD_TESTING:BOOL=ON

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
PLIST_SUB+=	CHOSEN_COMPILER_TYPE="GNU"
.else
PLIST_SUB+=	CHOSEN_COMPILER_TYPE="Clang"
.endif

post-extract:
	${MV} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/.ExternalData/* ${WRKSRC}/.ExternalData/
	${RM} -r ${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.post.mk>
