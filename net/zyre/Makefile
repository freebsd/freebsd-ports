PORTNAME=	zyre
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for proximity-based peer-to-peer applications
WWW=		https://github.com/zeromq/zyre

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libczmq.so:net/czmq \
		libzmq.so:net/libzmq4

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	zeromq
USE_LDCONFIG=	yes

CMAKE_OFF=	ZYRE_BUILD_STATIC
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4 compatibility, see https://github.com/zeromq/zyre/issues/760

.include <bsd.port.mk>
