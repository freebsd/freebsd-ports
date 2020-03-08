# $FreeBSD$

PORTNAME=	mkl-dnn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	math # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel(R) Math Kernel Library for Deep Neural Networks

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: shift count >= width of type (and other errors), see https://github.com/intel/mkl-dnn/issues/315

TEST_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	intel
GH_TAGNAME=	f32e21b
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_BROKEN_OFF=	still requires omp.h, see https://github.com/intel/mkl-dnn/issues/581

CXXFLAGS_amd64=	-msse4.1
CXXFLAGS_i386=	-msse4.1

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

do-test: # some tests are known to fail: https://github.com/intel/mkl-dnn/issues/350
	@${REINPLACE_CMD} 's| /bin/bash | ${LOCALBASE}/bin/bash |' ${WRKSRC}/tests/CMakeLists.txt
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
