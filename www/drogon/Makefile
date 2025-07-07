PORTNAME=	drogon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.11
CATEGORIES=	www

MAINTAINER=	zi@FreeBSD.org
COMMENT=	C++14/17/20-based HTTP web application framework
WWW=		https://github.com/drogonframework/drogon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp \
		libtrantor.so:net/trantor

USES=		cmake ssl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	drogonframework

CXXFLAGS+=	-Wno-error=unused-variable
CMAKE_ARGS=	-DCMAKE_CXX_COMPILER_ID=Clang
CMAKE_OFF=	BUILD_BROTLI BUILD_EXAMPLES BUILD_ORM \
		BUILD_YAML_CONFIG BUILD_DOC USE_SUBMODULE
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
