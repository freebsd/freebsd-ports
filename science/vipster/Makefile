PORTNAME=	vipster
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.1b-109
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gfb4a6ed
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystalline and molecular structure visualisation program
WWW=		https://sgsaenger.github.io/vipster/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	catch>0:devel/catch \
		cli11>0:devel/cli11 \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libtinyexpr.so:math/tinyexpr

USES=		cmake compiler:c++17-lang gl
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sgsaenger

LDFLAGS+=	-L${LOCALBASE}/lib -ltinyexpr

OPTIONS_DEFINE=		DESKTOP LAMMPS PYTHON
OPTIONS_DEFAULT=	DESKTOP
OPTIONS_SUB=		yes

CMAKE_OFF=		VIPSTER_DOWNLOAD_DEPENDENCIES \
			BUILD_TESTING

DESKTOP_DESC=		Build QT-based desktop app
DESKTOP_CMAKE_BOOL=	VIPSTER_DESKTOP
DESKTOP_USES=		qt:6
DESKTOP_USE=		QT=base

LAMMPS_DESC=		Interactive LAMMPS in desktop app
LAMMPS_CMAKE_BOOL=	VIPSTER_LAMMPS
LAMMPS_IMPLIES=		DESKTOP
LAMMPS_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			liblammps.so:science/lammps \
			libmpi.so:net/openmpi
LAMMPS_CONFLICTS_BUILD=	mpich

PYTHON_CMAKE_BOOL=	VIPSTER_PYLIB VIPSTER_PYWIDGET
PYTHON_BROKEN=		Bundles pybind11: https://github.com/sgsaenger/vipster/issues/23

PORTSCOUT=	limit:^[0-9][0-9a-z\.]*$$

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
