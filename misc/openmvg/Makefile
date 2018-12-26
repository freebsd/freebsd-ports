# $FreeBSD$

PORTNAME=	openmvg
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiple View Geometry (MVG) library

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/../LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	need to figure out which TARGET_ARCHITECTURE values correspond to other architectures, plus "generic" is broken

LIB_DEPENDS=	libflann_cpp.so:math/flann \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake eigen:3 jpeg qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	openMVG
GH_PROJECT=	openMVG
GH_TUPLE=	openMVG-thirdparty:cereal:37fca60:cereal/dependencies/cereal \
		openMVG-thirdparty:osi_clp:a25a980:osi/dependencies/osi_clp
WRKSRC_SUBDIR=	src
USE_QT=		core gui opengl svg widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DEIGEN_INCLUDE_DIR_HINTS=${LOCALBASE}/include/eigen3 \
		-DFLANN_INCLUDE_DIR_HINTS=${LOCALBASE}/include
CMAKE_ON=	OpenMVG_BUILD_SHARED
CMAKE_OFF=	OpenMVG_BUILD_EXAMPLES

CXXFLAGS+=	-fPIC \
		-I${LOCALBASE}/include # because flann is looked for in a wrong directiory: https://github.com/openMVG/openMVG/issues/1284

OPTIONS_SINGLE=			SIMD_${ARCH}
OPTIONS_SINGLE_SIMD_amd64=	K8 CORE MEROM NEHALEM
OPTIONS_SINGLE_SIMD_i386=	${OPTIONS_SINGLE_SIMD_amd64}
OPTIONS_DEFAULT_amd64=		K8
OPTIONS_DEFAULT_i386=		K8

SIMD_amd64_DESC=		Use SSE SIMD optimizations for
SIMD_i386_DESC=			${SIMD_amd64_DESC}
K8_DESC=			K8 architecture (SSE2)
CORE_DESC=			Core architecture (up to SSE3)
MEROM_DESC=			Merom architecture (up to SSSE3)
NEHALEM_DESC=			Nehalem architecture (up to SSE4.2)

K8_CMAKE_ON=			-DTARGET_ARCHITECTURE=k8
CORE_CMAKE_ON=			-DTARGET_ARCHITECTURE=core
MEROM_CMAKE_ON=			-DTARGET_ARCHITECTURE=merom
NEHALEM_CMAKE_ON=		-DTARGET_ARCHITECTURE=nehalem

.include <bsd.port.mk>
