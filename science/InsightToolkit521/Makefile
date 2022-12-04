PORTNAME=	InsightToolkit
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.1
CATEGORIES=	science biology
MASTER_SITES=	https://github.com/InsightSoftwareConsortium/ITK/releases/download/v${DISTVERSION}/:data
PKGNAMESUFFIX=	521
DISTFILES=	InsightData-${DISTVERSION}.tar.gz:data

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Insight Toolkit
WWW=		https://www.itk.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: always_inline function '_mm_cvtsd_si32' requires target feature 'sse2' (i386 doesn't have SSE2 enabled by default, and adding -msse2 doesn't help)

BUILD_DEPENDS=	googletest>=0:devel/googletest
LIB_DEPENDS=	libgdcmCommon.so:devel/gdcm \
		libexpat.so:textproc/expat2 \
		libfftw.so:math/fftw \
		libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff

USES=		cmake:testing compiler:c++11-lang eigen:3 jpeg pkgconfig python:test
USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit

USE_GITHUB=	yes
GH_ACCOUNT=	InsightSoftwareConsortium
GH_PROJECT=	ITK

CMAKE_ON=	BUILD_SHARED_LIBS \
		ITK_FORBID_DOWNLOADS \
		ITK_LEGACY_SILENT \
		ITK_USE_SYSTEM_EXPAT \
		ITK_USE_SYSTEM_FFTW \
		ITK_USE_SYSTEM_GDCM \
		ITK_USE_SYSTEM_HDF5 \
		ITK_USE_SYSTEM_JPEG \
		ITK_USE_SYSTEM_LIBRARIES \
		ITK_USE_SYSTEM_PNG \
		ITK_USE_SYSTEM_TIFF \
		ITK_USE_SYSTEM_ZLIB \
		Module_ITKIOMIC \
		Module_ITKIOTransformMINC \
		Module_ITKReview
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	ITK_USE_KWSTYLE BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING # 3 tests are known to fail, see https://github.com/InsightSoftwareConsortium/ITK/issues/3739

ITK_VER=	${PORTVERSION:R}

PLIST_SUB+=	ITK_VER=${ITK_VER}

OPTIONS_DEFINE=	EXAMPLES TESTING
EXAMPLES_DESC=	Build examples (very time consuming)
TESTING_DESC=	Build testing programs (very time consuming)

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES
TESTING_CMAKE_BOOL=	BUILD_TESTING

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
