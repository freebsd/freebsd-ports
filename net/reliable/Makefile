PORTNAME=	reliable
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.4
CATEGORIES=	net devel

MAINTAINER=	glenn@mas-bandwidth.com
COMMENT=	Reliability layer for UDP-based network protocols
WWW=		https://github.com/mas-bandwidth/reliable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

# noninja: the test binary is named "test", which collides with the Ninja
# generator's ctest alias when the test build is enabled
USES=		cmake:testing,noninja
USE_GITHUB=	yes
GH_ACCOUNT=	mas-bandwidth
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	RELIABLE_BUILD_TESTS
CMAKE_TESTING_ON=	RELIABLE_BUILD_TESTS

PLIST_FILES=	include/reliable.h \
		lib/libreliable.so \
		lib/libreliable.so.1 \
		lib/libreliable.so.${DISTVERSION} \
		libdata/pkgconfig/reliable.pc

.include <bsd.port.mk>
