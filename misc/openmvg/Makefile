PORTNAME=	openmvg
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiple View Geometry (MVG) library

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/../LICENSE

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	need to figure out which TARGET_ARCHITECTURE values correspond to other architectures, plus "generic" is broken

#HPP_DEPENDS=	cereal>0:devel/cereal # external cereal is currently broken, see https://github.com/openMVG/openMVG/issues/1963
#BUILD_DEPENDS=	${HPP_DEPENDS}
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libblas.so:math/blas \
		libcamd.so:math/suitesparse-camd \
		libCbc.so:math/cbc \
		libccolamd.so:math/suitesparse-ccolamd \
		libceres.so:math/ceres-solver \
		libCgl.so:math/cgl \
		libcholmod.so:math/suitesparse-cholmod \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libCoinUtils.so:math/coinutils \
		libcolamd.so:math/suitesparse-colamd \
		libcoinmumps.so:math/ipopt \
		libcxsparse.so:math/suitesparse-cxsparse \
		libemon.so:math/lemon \
		libflann_cpp.so:math/flann \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libjbig.so:graphics/jbigkit \
		libmetis.so:math/metis \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libpng.so:graphics/png \
		libspqr.so:math/suitesparse-spqr \
		libsuitesparseconfig.so:math/suitesparse-config \
		libtiff.so:graphics/tiff \
		libunwind.so:devel/libunwind
LIB_DEPENDS+=	liblz4.so:archivers/liblz4 # workaround for https://github.com/openMVG/openMVG/issues/1798
#RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake compiler:c++11-lang eigen:3 jpeg qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	openMVG
GH_PROJECT=	openMVG
GH_TUPLE=	openMVG-thirdparty:cereal:ac168fe:cereal/dependencies/cereal
WRKSRC_SUBDIR=	src
USE_QT=		core gui opengl svg widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DEIGEN_INCLUDE_DIR_HINTS=${LOCALBASE}/include/eigen3 \
		-DFLANN_INCLUDE_DIR_HINTS=${LOCALBASE}/include \
		-DLEMON_INCLUDE_DIR_HINTS=${LOCALBASE}/include \
		-DOSI_INCLUDE_DIR_HINTS=${LOCALBASE}/include \
		-DCOINUTILS_INCLUDE_DIR_HINTS=${LOCALBASE}/include \
		-DCLP_INCLUDE_DIR_HINTS=${LOCALBASE}/include \
		-DCERES_DIR_HINTS=${LOCALBASE}/include
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
	@${RM} -r ${STAGEDIR}${PREFIX}/include/openMVG_dependencies/osi_clp

.include <bsd.port.mk>
