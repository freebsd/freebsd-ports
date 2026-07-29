PORTNAME=	yojimbo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.3
CATEGORIES=	net

MAINTAINER=	glenn@mas-bandwidth.com
COMMENT=	Client/server network library for multiplayer games
WWW=		https://github.com/mas-bandwidth/yojimbo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${LOCALBASE}/include/serialize.h:devel/serialize
# libsodium is linked directly when present at build time (it is required
# when netcode is a static library, harmless with the shared one)
LIB_DEPENDS=	libnetcode.so:net/netcode \
		libreliable.so:net/reliable \
		libsodium.so:security/libsodium

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	mas-bandwidth
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS YOJIMBO_SYSTEM_DEPS YOJIMBO_BUILD_TESTS

# the test binary is written to ${WRKSRC}/bin by the upstream build;
# it is not installed
do-test:
	cd ${WRKSRC} && bin/test

.include <bsd.port.mk>
