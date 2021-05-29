# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	zxing-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	textproc

MAINTAINER=	kde@FreeBSD.org
COMMENT=	ZXing C++ Library for QR code recognition

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
