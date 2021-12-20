PORTNAME=	helib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of homomorphic encryption

LICENSE=	APACHE20

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc powerpcspe

LIB_DEPENDS=	libgmp.so:math/gmp \
		libntl.so:math/ntl

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	homenc
GH_PROJECT=	HElib
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED
CMAKE_ARGS=	-DNTL_DIR=${LOCALBASE}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_TEST:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
