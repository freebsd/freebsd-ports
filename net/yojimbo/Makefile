PORTNAME=	yojimbo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.1
CATEGORIES=	net

MAINTAINER=	glenn@mas-bandwidth.com
COMMENT=	Client/server network library for multiplayer games
WWW=		https://github.com/mas-bandwidth/yojimbo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	serialize>=2.1.5:devel/serialize \
		netcode>=1.5.0:net/netcode \
		reliable>=1.4.6:net/reliable
# libsodium is linked directly when present at build time (it is required
# when netcode is a static library, harmless with the shared one)
LIB_DEPENDS=	libnetcode.so:net/netcode \
		libreliable.so:net/reliable \
		libsodium.so:security/libsodium
RUN_DEPENDS=	serialize>=2.1.5:devel/serialize \
		netcode>=1.5.0:net/netcode \
		reliable>=1.4.6:net/reliable

# noninja: the test binary is named "test", which collides with the Ninja
# generator's ctest alias when the test build is enabled
USES=		cmake:testing,noninja
USE_GITHUB=	yes
GH_ACCOUNT=	mas-bandwidth
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS YOJIMBO_SYSTEM_DEPS
CMAKE_OFF=	YOJIMBO_BUILD_TESTS
CMAKE_TESTING_ON=	YOJIMBO_BUILD_TESTS

.include <bsd.port.mk>
