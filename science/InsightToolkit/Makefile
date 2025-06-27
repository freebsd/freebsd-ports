PORTNAME=	InsightToolkit
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.0
PORTREVISION=	8
CATEGORIES=	science biology
MASTER_SITES=	https://github.com/InsightSoftwareConsortium/ITK/releases/download/v${DISTVERSION}/:data
DISTFILES=	InsightData-${DISTVERSION}.tar.gz:data

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Insight Toolkit
WWW=		https://www.itk.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	googletest>=0:devel/googletest # gtest required for build, see https://github.com/InsightSoftwareConsortium/ITK/issues/3750
LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libfreetype.so:print/freetype2 \
		libgdcmCommon.so:devel/gdcm \
		libexpat.so:textproc/expat2 \
		libfftw.so:math/fftw \
		libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff \
		libvcl.so:misc/vxl
# dependencies for optional modules
LIB_DEPENDS+=	libdcmjpls.so:graphics/dcmtk \
		libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang eigen:3,build,run gl jpeg localbase:ldflags pkgconfig python:run,test xorg
USE_GL=		opengl
USE_XORG=	x11
USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit

USE_GITHUB=	yes
GH_ACCOUNT=	InsightSoftwareConsortium
GH_PROJECT=	ITK

CMAKE_ON=	BUILD_SHARED_LIBS \
		ITK_LEGACY_SILENT \
		ITK_USE_SYSTEM_DCMTK \
		ITK_USE_SYSTEM_DOUBLECONVERSION \
		ITK_USE_SYSTEM_EIGEN \
		ITK_USE_SYSTEM_EXPAT \
		ITK_USE_SYSTEM_FFTW \
		ITK_USE_SYSTEM_GDCM \
		ITK_USE_SYSTEM_HDF5 \
		ITK_USE_SYSTEM_JPEG \
		ITK_USE_SYSTEM_LIBRARIES \
		ITK_USE_SYSTEM_PNG \
		ITK_USE_SYSTEM_TIFF \
		ITK_USE_SYSTEM_VXL \
		ITK_USE_SYSTEM_ZLIB \
		Module_ITKIOTransformMINC \
		Module_ITKIOPNG \
		Module_ITKReview
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	ITK_USE_KWSTYLE BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING # 4 tests are known to fail, see https://github.com/InsightSoftwareConsortium/ITK/issues/3739

#LDFLAGS+=	-lcompat # workaround for: ld: error: lib/liblpsolve55.so.5.5.2: undefined reference to ftime
LDFLAGS+=	-L${WRKSRC} -lftime # workaround for: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=257789, otherwise the above line should suffice

ITK_VER=	${PORTVERSION:R}

PLIST_SUB+=	ITK_VER=${ITK_VER}

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC=	Build examples (very time consuming)

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

BINARY_ALIAS=	git=${FILESDIR}/fake-git fetch=false

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
PLIST_SUB+=	CHOSEN_COMPILER_TYPE="GNU"
.else
PLIST_SUB+=	CHOSEN_COMPILER_TYPE="Clang"
.endif

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/.ExternalData/* ${WRKSRC}/.ExternalData/
	@${RM} -r ${WRKDIR}/${PORTNAME}-${DISTVERSION}

pre-configure: # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=257789
	@${SETENV} ${MAKE_ENV} ${CC} -c -fPIC ${FILESDIR}/ftime.c -o ${WRKSRC}/libftime.o
	@${AR} -rcs ${WRKSRC}/libftime.a ${WRKSRC}/libftime.o

post-configure: # fix conflict with lp_solve by renaming the shared library to liblp_solve55_itk, see https://github.com/InsightSoftwareConsortium/ITK/issues/4031
	@${REINPLACE_CMD} \
		-e 's|lpsolve55|lpsolve55_itk|g' \
		${WRKSRC}/Modules/Remote/RTK/CMakeLists.txt \
		${WRKSRC}/Modules/Remote/RTK/src/CMakeLists.txt \
		${WRKSRC}/Modules/Remote/RTK/utilities/lp_solve/CMakeLists.txt


post-install: # remove contentless docs
	@${RM} -r ${STAGEDIR}${PREFIX}/share

.include <Makefile.remote_modules>
.include <../../math/vtk9/Makefile.version>
.include <bsd.port.post.mk>
