PORTNAME=	kuku
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cuckoo hashing library written in C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	Kuku

CMAKE_ON=	BUILD_SHARED_LIBS

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DKUKU_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./bin/kukutest

.include <bsd.port.mk>
