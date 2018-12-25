# $FreeBSD$

PORTNAME=	sdformat
DISTVERSION=	8.0.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulation Description Format (SDF) parser and description files

LICENSE=	APACHE20

BUILD_DEPENDS=	ignition-cmake==2:devel/ignition-cmake \
		ignition-tools>0:devel/ignition-tools
LIB_DEPENDS=	libignition-math6.so:math/ignition-math \
		libconsole_bridge.so:misc/console-bridge \
		libtinyxml2.so:textproc/tinyxml2 \
		liburdfdom_world.so:misc/urdfdom
RUN_DEPENDS=	ignition-tools>0:devel/ignition-tools

USES=		cmake compiler:c++17-lang pkgconfig
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

BB_ACCOUNT=	osrf
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	f555f9a69f8f

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_SUB+=	INCSUBDIR=${PORTNAME}-${DISTVERSION:R}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
