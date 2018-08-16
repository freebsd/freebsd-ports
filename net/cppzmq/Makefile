# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppzmq
PORTVERSION=	4.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	vd@FreeBSD.org
COMMENT=	C++ bindings for 0MQ

LICENSE=	MIT

LIB_DEPENDS=	libzmq.so:net/libzmq4

NO_ARCH=	yes

USES=		cmake pkgconfig
CMAKE_ARGS=	--no-warn-unused-cli -Wno-dev -DCPPZMQ_BUILD_TESTS:BOOL=OFF

# cppzmq is included in libzmq2
CONFLICTS_INSTALL=	libzmq2

USE_GITHUB=	yes
GH_ACCOUNT=	zeromq

PLIST_FILES=	\
	include/zmq.hpp \
	include/zmq_addon.hpp \
	share/cmake/Modules/cppzmqConfig.cmake \
	share/cmake/Modules/cppzmqConfigVersion.cmake \
	share/cmake/Modules/cppzmqTargets.cmake \
	share/cmake/Modules/libzmq-pkg-config/FindZeroMQ.cmake

post-patch:
	${SED} -i '.orig' \
		-e 's|share/cmake/$${PROJECT_NAME}|share/cmake/Modules|' \
		${WRKSRC}/CMakeLists.txt
	${SED} -i '.orig' \
		-e 's|ZeroMQ_LIBRARY AND ZeroMQ_STATIC_LIBRARY|ZeroMQ_LIBRARY|' \
		${WRKSRC}/libzmq-pkg-config/FindZeroMQ.cmake

.include <bsd.port.mk>
