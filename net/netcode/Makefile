PORTNAME=	netcode
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.5
CATEGORIES=	net

MAINTAINER=	glenn@mas-bandwidth.com
COMMENT=	Secure client/server connections over UDP
WWW=		https://github.com/mas-bandwidth/netcode

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libsodium.so:security/libsodium

# noninja: the test binary is named "test", which collides with the Ninja
# generator's ctest alias when the test build is enabled
USES=		cmake:testing,noninja
USE_GITHUB=	yes
GH_ACCOUNT=	mas-bandwidth
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS NETCODE_SYSTEM_SODIUM
CMAKE_OFF=	NETCODE_BUILD_TESTS
CMAKE_TESTING_ON=	NETCODE_BUILD_TESTS

PLIST_FILES=	include/netcode.h \
		lib/libnetcode.so \
		lib/libnetcode.so.1 \
		lib/libnetcode.so.${DISTVERSION}

.include <bsd.port.mk>
