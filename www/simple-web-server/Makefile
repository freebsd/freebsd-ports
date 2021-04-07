PORTNAME=	simple-web-server
DISTVERSION=	3.0.2
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HTTP and HTTPS server and client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang
USE_GITLAB=	yes
GL_ACCOUNT=	eidheim
GL_PROJECT=	Simple-Web-Server
GL_COMMIT=	0f8b26ff19d757db039d6f70e252219326cc3d8f

NO_ARCH=	yes
NO_BUILD=	yes

do-test: # one testcase is known to fail: https://gitlab.com/eidheim/Simple-Web-Server/-/issues/294
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
