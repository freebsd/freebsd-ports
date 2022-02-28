PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	9.2
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0.txt

PATCH_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libcoinasl.so:math/asl \
		libcoinmetis.so:math/ipopt \
		libCoinUtils.so:math/coinutils \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libOsiClp.so:math/clp \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf

USES=		blaslapack cmake:testing compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_PYTHON BUILD_DEPS INSTALL_BUILD_DEPS BUILD_EXAMPLES BUILD_SAMPLES
CMAKE_ON=	BUILD_CXX
CMAKE_TESTING_ON=	BUILD_EXAMPLES BUILD_CXX_EXAMPLES

CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

OPTIONS_DEFINE=		FLATZINC SCIP
OPTIONS_DEFAULT=	FLATZINC #SCIP
OPTIONS_SUB=		yes

FLATZINC_DESC=		Build FlatZinc - MiniZinc interface
FLATZINC_CMAKE_BOOL=	BUILD_FLATZINC

SCIP_DESC=		Use the SCIP solver # SCIP package isn't built because of licensing restrictions
SCIP_CMAKE_BOOL=	USE_SCIP
SCIP_LIB_DEPENDS=	libscip.so:math/SCIP

post-patch:
	# fix for https://github.com/google/or-tools/issues/2526 suggested there
	@gsed -i '11i \ \ LINKER_LANGUAGE Cxx' \
		${WRKSRC}/ortools/init/CMakeLists.txt

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
