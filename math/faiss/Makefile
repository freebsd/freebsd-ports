# $FreeBSD$

PORTNAME=	faiss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.3-72
DISTVERSIONSUFFIX=	-gc97f890
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient similarity search & clustering of dense vectors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Links with libopenblasp-rN.N.N.so which is installed by math/openblas only on amd64,i386 architectures

LIB_DEPENDS=	libopenblasp-r0.3.9.so:math/openblas

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FAISS_ENABLE_GPU FAISS_ENABLE_PYTHON

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
