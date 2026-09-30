PORTNAME=	libuvc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.8
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform library for USB video devices
WWW=		https://libuvc.github.io/libuvc/ \
		https://github.com/libuvc/libuvc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing jpeg pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_EXAMPLE
CMAKE_TESTING_ON=	BUILD_TESTING

# tests as of 0.0.8: 100% tests passed, 0 tests failed out of 170

.include <bsd.port.mk>
