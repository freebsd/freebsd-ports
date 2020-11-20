# $FreeBSD$

PORTNAME=	cglm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Highly optimized graphics math (glm) for C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	recp
USE_LDCONFIG=	yes

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DCGLM_USE_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
