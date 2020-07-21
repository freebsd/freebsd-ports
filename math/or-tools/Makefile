# $FreeBSD$

PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	7.7
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

USES=		blaslapack cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_DEPS INSTALL_BUILD_DEPS BUILD_PYTHON BUILD_EXAMPLES
CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}
BUILD_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

post-configure: # https://github.com/google/or-tools/issues/2109
	@${REINPLACE_CMD} -e 's|protobuf::protoc|protoc -I${LOCALBASE}/include| ; s|protobuf$$:$$:protoc||' ${BUILD_WRKSRC}/build.ninja

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
