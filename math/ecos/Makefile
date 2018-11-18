# $FreeBSD$

PORTNAME=	ecos
DISTVERSION=	2.0.7
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight conic solver for second-order cone programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	embotech
USE_LDCONFIG=	yes

ALL_TARGET=	shared

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ecos
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/ecos
	${INSTALL_LIB} ${WRKSRC}/libecos.so ${STAGEDIR}${PREFIX}/lib

do-test: # some tests are known to fail: https://github.com/embotech/ecos/issues/170
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} test && \
		${ECHO} "===> Running ${PORTNAME} tests: ecostester" && \
		(./ecostester || true) && \
		${ECHO} "===> Running ${PORTNAME} tests: ecos_bb_test" && \
		./ecos_bb_test

demos: build # runs the demo problems
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} demo && \
		./runecos && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} runecosexp && \
		./runecosexp

.include <bsd.port.mk>
