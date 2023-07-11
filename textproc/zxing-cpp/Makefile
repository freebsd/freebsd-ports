PORTNAME=	zxing-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	textproc

PATCH_SITES=	https://github.com/zxing-cpp/zxing-cpp/commit/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	ZXing C++ Library for QR code recognition
WWW=		https://github.com/nu-book/zxing-cpp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang iconv
USE_GITHUB=	yes
GH_ACCOUNT=	nu-book
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
# Disable
# * examples (no installation target)
# * blackbox test (fetches third party source)
CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_BLACKBOX_TESTS

.include <bsd.port.mk>
