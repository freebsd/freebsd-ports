# $FreeBSD$

PORTNAME=	hmat-oss
DISTVERSION=	1.5.0-348
DISTVERSIONSUFFIX=	-g76beaf3
PORTREVISION=	5
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hierarchical matrix C/C++ library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake compiler:openmp
USE_GITHUB=	yes
GH_ACCOUNT=	jeromerobert
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_EXAMPLES:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${REINPLACE_CMD} "s|#define OPENBLAS_DISABLE_THREADS|\/\/&|" ${BUILD_WRKSRC}/config.h && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
