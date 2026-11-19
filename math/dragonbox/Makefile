PORTNAME=	dragonbox
DISTVERSION=	1.1.3
CATEGORIES=	math devel

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Floating-point binary-to-decimal conversion library
WWW=		https://github.com/jk-jeon/dragonbox

LICENSE=	APACHE20 BSL
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-Apache2-LLVM
LICENSE_FILE_BSL=	${WRKSRC}/LICENSE-Boost

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	jk-jeon
USE_LDCONFIG=	yes

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	DRAGONBOX_ENABLE_SUBPROJECT

PLIST_SUB=	PORTVERSION=${PORTVERSION}

# tests as of 1.1.3: 100% tests passed, 0 tests failed out of 7

.include <bsd.port.mk>
