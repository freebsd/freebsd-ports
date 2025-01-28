PORTNAME=	flint
DISTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.flintlib.org/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast library for number theory
WWW=		https://flintlib.org \
		https://github.com/flintlib/flint

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libopenblas.so:math/openblas

USES=		cmake compiler:c++11-lang pkgconfig python:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		NTL
OPTIONS_DEFAULT=	NTL

NTL_DESC=		Victor Shoup's Number Theory Library
NTL_CMAKE_BOOL=		WITH_NTL
NTL_LIB_DEPENDS=	libntl.so:math/ntl

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
