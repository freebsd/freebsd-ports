PORTNAME=	iwnet
PORTVERSION=	g20220223
CATEGORIES=	net www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Asynchronous HTTP library with websockets, SSL, routing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/iowow/iowow.h:databases/iowow

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	Softmotions
GH_TAGNAME=	0569ab0
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_TESTS:BOOL=ON

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/USES_TERMINAL/d' \
		${WRKSRC}/tools/CMakeLists.txt
	@${REINPLACE_CMD} -e '51s:malloc(:calloc(1, :' \
		${WRKSRC}/tools/mimegen.c

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
