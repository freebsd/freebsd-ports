PORTNAME=	iwnet
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Asynchronous HTTP library with websockets, SSL, routing
WWW=		https://github.com/Softmotions/iwnet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/iowow/iowow.h:databases/iowow

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	Softmotions
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_TESTS:BOOL=ON

OPTIONS_DEFINE=	DOCS

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
