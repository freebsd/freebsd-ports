PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	9.5
PORTREVISION=	7
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools
WWW=		https://github.com/google/or-tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PATCH_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libOsiClp.so:math/clp \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2

USES=		blaslapack cmake:testing compiler:c++17-lang eigen:3 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_PYTHON BUILD_DEPS INSTALL_BUILD_DEPS BUILD_EXAMPLES BUILD_SAMPLES
CMAKE_ON=	BUILD_CXX
CMAKE_TESTING_ON=	BUILD_EXAMPLES BUILD_CXX_EXAMPLES
CXXFLAGS+=	-DABSL_LEGACY_THREAD_ANNOTATIONS

CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

OPTIONS_DEFINE=		DOCS FLATZINC SCIP
OPTIONS_DEFAULT=	FLATZINC #SCIP
OPTIONS_SUB=		yes

FLATZINC_DESC=		Build FlatZinc - MiniZinc interface
FLATZINC_CMAKE_BOOL=	BUILD_FLATZINC

SCIP_DESC=		Use the SCIP solver # SCIP package isn't built because of licensing restrictions
SCIP_CMAKE_BOOL=	USE_SCIP
SCIP_LIB_DEPENDS=	libscip.so:math/SCIP

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-//}
PORTDOCS=	*

# 3 tests are known to fail, see https://github.com/google/or-tools/issues/3429

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
