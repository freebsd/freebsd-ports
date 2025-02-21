PORTNAME=	zxing-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	textproc

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ library for linear/matrix barcode recognition
WWW=		https://github.com/zxing-cpp/zxing-cpp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++20-lang iconv pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
# Disable
# * examples (no installation target)
# * blackbox test (fetches third party source)
CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_BLACKBOX_TESTS
CMAKE_TESTING_ON=	ZXING_UNIT_TESTS

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
