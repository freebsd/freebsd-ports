PORTNAME=	opennn
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.5
PORTREVISION=	1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open neural networks library
WWW=		https://www.opennn.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

USES=		cmake:testing compiler:c++11-lang dos2unix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Artelnics

DOS2UNIX_FILES=	opennn/CMakeLists.txt

CMAKE_OFF=	OpenNN_BUILD_EXAMPLES OpenNN_BUILD_TESTS
CMAKE_TESTING_ON=	OpenNN_BUILD_TESTS # some tests fail, see https://github.com/Artelnics/opennn/issues/229
CMAKE_TESTING_TARGET=	tests

LDFLAGS+=	-lomp -pthread # https://github.com/Artelnics/opennn/issues/182

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME} && ${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${PORTNAME}/libopennn.so ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopennn.so

post-test:
	@cd ${TEST_WRKSRC} && (${ECHO} suite | tests/tests)

.include <bsd.port.mk>
