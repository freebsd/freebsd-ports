PORTNAME=	xtensor-io
DISTVERSION=	0.13.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Xtensor plugin to read/write images, audio files, numpy npz and HDF5

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

HPP_DEPENDS=	xtensor>0:math/xtensor
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	xtensor-stack

NO_BUILD=	yes
NO_ARCH=	yes

do-test: install # tests fail to compile, see https://github.com/xtensor-stack/xtensor-io/issues/168
	@cd ${WRKSRC}/test && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} . && \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && \
		${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xtest

.include <bsd.port.mk>
