# $FreeBSD$

PORTNAME=	vipster
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16b
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystalline and molecular structure visualisation program

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	sgsaenger
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DESKTOP PYTHON
OPTIONS_DEFAULT=	DESKTOP
OPTIONS_SUB=		yes

DESKTOP_DESC=		Build QT-based desktop app
DESKTOP_CMAKE_BOOL=	DESKTOP
DESKTOP_USES=		qt:5
DESKTOP_USE=		QT=core,gui,widgets,buildtools_build,qmake_build

PYTHON_CMAKE_BOOL=	PYTHON
PYTHON_BROKEN=		Bundles pybind11: https://github.com/sgsaenger/vipster/issues/23

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
