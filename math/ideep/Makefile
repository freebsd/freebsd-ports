PORTNAME=	ideep
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0-119
DISTVERSIONSUFFIX=	-gb57539e
CATEGORIES=	math # neural-networks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chainer module for numpy-like API and DNN acceleration using MKL-DNN

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${LOCALBASE}/include/rapidcheck.h:devel/rapidcheck

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes

do-test: # tests broken: https://github.com/intel/ideep/issues/34 and assume bundled mkl-dnn
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
