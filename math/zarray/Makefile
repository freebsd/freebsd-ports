PORTNAME=	zarray
DISTVERSION=	0.1.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamically typed N-D expression system based on xtensor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

HPP_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		xtensor>0:math/xtensor
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	xtensor-stack

NO_BUILD=	yes
NO_ARCH=	yes

do-test: install
	@cd ${WRKSRC}/test && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} . && \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xtest

.include <bsd.port.mk>
