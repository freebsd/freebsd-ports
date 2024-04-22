PORTNAME=	quantum++
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1
CATEGORIES=	misc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only general purpose quantum computing library
WWW=		https://github.com/softwareQinc/qpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang eigen:3,build,run localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	softwareQinc
GH_PROJECT=	qpp

CMAKE_TESTING_TARGET=	unit_tests

NO_BUILD=	yes
NO_ARCH=	yes

post-test: # run tests
	@${BUILD_WRKSRC}/unit_tests/unit_tests

.include <bsd.port.mk>
