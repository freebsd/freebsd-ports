PORTNAME=	zxing-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	textproc

PATCH_SITES=	https://github.com/zxing-cpp/zxing-cpp/commit/
PATCHFILES=	23c19c5f98602a4d69d1667fff99678308b28b5b.diff:-p1

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
