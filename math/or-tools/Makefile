# $FreeBSD$

PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	8.2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0.txt

LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libOsiClp.so:math/clp \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf

USES=		blaslapack cmake compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_PYTHON BUILD_DEPS INSTALL_BUILD_DEPS BUILD_EXAMPLES BUILD_SAMPLES
CMAKE_ON=	BUILD_CXX
CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

OPTIONS_DEFINE=		SCIP
#OPTIONS_DEFAULT=	SCIP

SCIP_DESC=		Use the SCIP solver # SCIP package isn't built because of licensing restrictions
SCIP_CMAKE_BOOL=	USE_SCIP
SCIP_LIB_DEPENDS=	libscip.so:math/SCIP

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
