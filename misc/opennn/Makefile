PORTNAME=	opennn
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.4
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open neural networks library
WWW=		https://www.opennn.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_armv7=	gcc13 fails: error: use of built-in trait '__remove_cvref(_InIter1)' in function signature, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278630

USES=		cmake:testing dos2unix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Artelnics

DOS2UNIX_FILES=	opennn/CMakeLists.txt

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	OpenNN_BUILD_EXAMPLES OpenNN_BUILD_TESTS
CMAKE_TESTING_ON=	OpenNN_BUILD_TESTS # some tests fail, see https://github.com/Artelnics/opennn/issues/229
CMAKE_TESTING_TARGET=	tests

CXXFLAGS_powerpc=	-O1
CXXFLAGS_powerpc64=	-mvsx
LDFLAGS+=	-pthread
LDFLAGS_powerpc=	-latomic

.if !exists(/usr/include/omp.h)
LDFLAGS+=	-fopenmp
USES+=		compiler:gcc-c++11-lib
.else
LDFLAGS+=	-lomp # https://github.com/Artelnics/opennn/issues/182
USES+=		compiler:c++11-lang
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME} && ${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${PORTNAME}/libopennn.so ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopennn.so

post-test:
	@cd ${TEST_WRKSRC} && (${ECHO} suite | tests/tests)

.include <bsd.port.mk>
