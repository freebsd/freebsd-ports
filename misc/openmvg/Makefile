# $FreeBSD$

PORTNAME=	openmvg
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiple View Geometry (MVG) library

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/../LICENSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	need to figure out which TARGET_ARCHITECTURE values correspond to other architectures, plus "generic" is broken

HPP_DEPENDS=	cereal>0:devel/cereal
BUILD_DEPENDS=	${HPP_DEPENDS}
LIB_DEPENDS=	libflann_cpp.so:math/flann \
		libopenblas.so:math/openblas \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
LIB_DEPENDS+=	liblz4.so:archivers/liblz4 # workaround for https://github.com/openMVG/openMVG/issues/1798
RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake compiler:c++11-lang eigen:3 jpeg qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	openMVG
GH_PROJECT=	openMVG
GH_TUPLE=	openMVG-thirdparty:osi_clp:a25a980:osi/dependencies/osi_clp
WRKSRC_SUBDIR=	src
USE_QT=		core gui opengl svg widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

CONFLICTS_BUILD=	Clp CoinMP # libopenMVG_lemon.so: undefined reference to ClpSimplex::setRowLower(int, double)

CMAKE_ARGS=	-DCEREAL_INCLUDE_DIR_HINTS=${LOCALBASE}/include \
		-DEIGEN_INCLUDE_DIR_HINTS=${LOCALBASE}/include/eigen3 \
		-DFLANN_INCLUDE_DIR_HINTS=${LOCALBASE}/include
CMAKE_ON=	OpenMVG_BUILD_SHARED
CMAKE_OFF=	OpenMVG_BUILD_TESTS OpenMVG_BUILD_EXAMPLES

CXXFLAGS+=	-fPIC \
		-I${LOCALBASE}/include # because flann is looked for in a wrong directiory: https://github.com/openMVG/openMVG/issues/1284
LDFLAGS+=	-L${LOCALBASE}/lib -llz4 # workaround for https://github.com/openMVG/openMVG/issues/1798

OPTIONS_SINGLE=			SIMD_${ARCH:tu}
OPTIONS_SINGLE_SIMD_AMD64=	K8 CORE MEROM NEHALEM
OPTIONS_SINGLE_SIMD_I386=	${OPTIONS_SINGLE_SIMD_AMD64}
OPTIONS_DEFAULT_amd64=		K8
OPTIONS_DEFAULT_i386=		K8

SIMD_AMD64_DESC=		Use SSE SIMD optimizations for
SIMD_I386_DESC=			${SIMD_AMD64_DESC}
K8_DESC=			K8 architecture (SSE2)
CORE_DESC=			Core architecture (up to SSE3)
MEROM_DESC=			Merom architecture (up to SSSE3)
NEHALEM_DESC=			Nehalem architecture (up to SSE4.2)

K8_CMAKE_ON=			-DTARGET_ARCHITECTURE=k8
CORE_CMAKE_ON=			-DTARGET_ARCHITECTURE=core
MEROM_CMAKE_ON=			-DTARGET_ARCHITECTURE=merom
NEHALEM_CMAKE_ON=		-DTARGET_ARCHITECTURE=nehalem

post-install:
	cd ${STAGEDIR}${PREFIX}/include/openMVG_dependencies && ${RMDIR} cereal

.include <bsd.port.mk>
