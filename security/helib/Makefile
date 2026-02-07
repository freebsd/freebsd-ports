PORTNAME=	helib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of homomorphic encryption
WWW=		https://github.com/homenc/HElib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc powerpcspe

LIB_DEPENDS=	libgmp.so:math/gmp \
		libntl.so:math/ntl

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	homenc
GH_PROJECT=	HElib

CMAKE_ON=	BUILD_SHARED
CMAKE_OFF=	PEDANTIC_BUILD # disable -Werror that breaks tests build
CMAKE_TESTING_ON=	ENABLE_TEST
CMAKE_ARGS=	-DNTL_DIR=${LOCALBASE}

xdo-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
