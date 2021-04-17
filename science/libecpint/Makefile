PORTNAME=	libecpint
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6
CATEGORIES=	science devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for the evaluation of integrals over effective core potentials

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lang python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	robashaw

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	LIBECPINT_BUILD_TESTS LIBECPINT_BUILD_DOCS

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DLIBECPINT_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		ctest

.include <bsd.port.mk>
