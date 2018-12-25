# $FreeBSD$

PORTNAME=	qpOASES
DISTVERSION=	3.2.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME}/
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for online active set strategy quadratic programming problems

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake fortran tar:tgz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	QPOASES_BUILD_EXAMPLES

LDFLAGS+=	${LOCALBASE}/lib/libopenblas.so

EXAMPLES=	example1 example1a example1b example2 example4 example5 exampleLP qrecipe # there are some other examples, but they need additional files/packages to run

post-patch:
	@truncate -s 0 ${WRKSRC}/src/BLASReplacement.cpp ${WRKSRC}/src/LAPACKReplacement.cpp

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DQPOASES_BUILD_EXAMPLES:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		for e in ${EXAMPLES}; do \
			${ECHO} "=== Running example $${e} ===" && \
			${BUILD_WRKSRC}/bin/$${e}; \
		done

.include <bsd.port.mk>
