PORTNAME=	xtensor-blas
DISTVERSION=	0.23.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BLAS extension to xtensor
WWW=		https://github.com/xtensor-stack/xtensor-blas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

HPP_DEPENDS=	xtensor>0:math/xtensor
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}
TEST_DEPENDS=	doctest>0:devel/doctest

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

# tests as of 0.23.0:
# [doctest] test cases:  77 |  77 passed | 0 failed | 0 skipped
# [doctest] assertions: 311 | 311 passed | 0 failed |
# [doctest] Status: SUCCESS!

.include <bsd.port.mk>
