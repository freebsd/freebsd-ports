# $FreeBSD$

PORTNAME=	urdfdom
DISTVERSION=	1.0.0-9
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g1857a55
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unified Robot Description Format (URDF) parser

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	urdfdom-headers>0:misc/urdfdom-headers
LIB_DEPENDS=	libconsole_bridge.so:misc/console-bridge \
		libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	urdfdom-headers>0:misc/urdfdom-headers

USES=		compiler:c++11-lang cmake
USE_GITHUB=	yes
GH_ACCOUNT=	ros
USE_LDCONFIG=	yes

do-test: # some tests are known to fail: https://github.com/ros/urdfdom/issues/118
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
