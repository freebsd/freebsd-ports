# $FreeBSD$

PORTNAME=	mkl-dnn
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel(R) Math Kernel Library for Deep Neural Networks

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_10=	invalid value 'internal' in '-fvisibility internal'

TEST_DEPENDS=	bash:shells/bash

USES=		cmake:outsource compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes

PLIST_FILES=	include/mkldnn.h \
		include/mkldnn.hpp \
		include/mkldnn_debug.h \
		include/mkldnn_types.h \
		lib/libmkldnn.so \
		lib/libmkldnn.so.0 \
		lib/libmkldnn.so.0.16.0

do-test:
	@${REINPLACE_CMD} 's| /bin/bash | ${LOCALBASE}/bin/bash |' ${WRKSRC}/tests/CMakeLists.txt
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
