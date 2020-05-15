# $FreeBSD$

PORTNAME=	vipster
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18b.20200514
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystalline and molecular structure visualisation program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cli11>0:devel/cli11 \
		libfmt>0:devel/libfmt \
		nlohmann-json>0:devel/nlohmann-json

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	sgsaenger
GH_TAGNAME=	714970a148bc8f6801c8e98120aa884da6ca801c
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DESKTOP LAMMPS PYTHON
OPTIONS_DEFAULT=	DESKTOP
OPTIONS_SUB=		yes

CMAKE_OFF=		VIPSTER_PYWIDGET

DESKTOP_DESC=		Build QT-based desktop app
DESKTOP_CMAKE_BOOL=	VIPSTER_DESKTOP
DESKTOP_USES=		qt:5
DESKTOP_USE=		QT=core,gui,widgets,buildtools_build,qmake_build

LAMMPS_DESC=		Interactive LAMMPS in desktop app
LAMMPS_CMAKE_BOOL=	VIPSTER_LAMMPS
LAMMPS_IMPLIES=		DESKTOP
LAMMPS_BROKEN=		https://github.com/sgsaenger/vipster/issues/39

PYTHON_CMAKE_BOOL=	PYTHON PYSHELL
PYTHON_BROKEN=		Bundles pybind11: https://github.com/sgsaenger/vipster/issues/23

PORTSCOUT=	limit:^[0-9][0-9a-z\.]*$$

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
