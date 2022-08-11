PORTNAME=	tinyxml2
PORTVERSION=	9.0.0
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small C++ XML Parser

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:insource compiler:c++11-lang cpe dos2unix pathfix

CMAKE_OFF=	BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	leethomason
USE_GITHUB=	yes

CPE_VENDOR=	tinyxml2_project

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_DEBUG_POSTFIX/d' ${WRKSRC}/CMakeLists.txt

post-install:
	${AR} cq ${STAGEDIR}${PREFIX}/lib/libtinyxml2.a ${WRKSRC}/CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o
	
post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} resources ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xmltest && ./xmltest

.include <bsd.port.mk>
