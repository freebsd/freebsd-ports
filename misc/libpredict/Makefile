PORTNAME=	libpredict
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Satellite orbit prediction library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	la1k
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

PLIST_FILES=	include/predict/predict.h \
		lib/libpredict.so \
		lib/libpredict.so.${DISTVERSION:R:R} \
		lib/libpredict.so.${DISTVERSION} \
		libdata/pkgconfig/predict.pc

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
