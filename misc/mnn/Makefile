# $FreeBSD$

PORTNAME=	mnn
DISTVERSION=	0.2.1.5
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight deep neural network inference engine

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash

USES=		cmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	alibaba
GH_PROJECT=	MNN
SHEBANG_GLOB=	*.sh
USE_LDCONFIG=	yes

CXXFLAGS+=	-pthread
LDFLAGS+=	-pthread

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DMNN_BUILD_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		(cd ${BUILD_WRKSRC} && ./run_test.out)

.include <bsd.port.mk>
