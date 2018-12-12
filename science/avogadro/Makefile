# Created by: Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
# $FreeBSD$

PORTNAME=	avogadro
DISTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced molecular editor and viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

CONFLICTS_INSTALL=	libmsym

BROKEN_armv6=		fails to compile: eigen2/Eigen/src/Core/Assign.h: you mixed different numeric types in 'Eigen::ei_static_assert<false>'
BROKEN_armv7=		fails to compile: eigen2/Eigen/src/Core/Assign.h: you mixed different numeric types in 'Eigen::ei_static_assert<false>'

LIB_DEPENDS=	libopenbabel.so:science/openbabel

# We need to add a RUN_DEPENDS on eigen2, as the cmake file shiped with
# avogadro to use it, contains 'find_package(Eigen2 REQUIRED)'.
USES=		cmake desktop-file-utils eigen:2,build,run gl pkgconfig qt:4
USE_GL=		glu gl
USE_QT=		corelib gui network opengl \
		linguisttools_build moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DENABLE_GLSL=OFF \
		-DQT_MKSPECS_RELATIVE=share/qt4/mkspecs
USE_XORG=	x11
USE_LDCONFIG=	yes

CFLAGS+=	-idirafter ${LOCALBASE}/include/eigen2 \
		-idirafter ${LOCALBASE}/include \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=		python:2.7
PYTHON_BUILD_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}sip>0:devel/py-sip@${PY_FLAVOR}
PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}sip>0:devel/py-sip@${PY_FLAVOR}
PYTHON_CMAKE_ON=	-DENABLE_PYTHON=ON \
			-DPYTHON_INCLUDE_DIR:PATH=${WRKDIR}/include/${PYTHON_VERSION}
PYTHON_CMAKE_OFF=	-DENABLE_PYTHON=OFF

post-patch:
	@${REINPLACE_CMD} -e \
		'/FLAGS_RELEASE/s|^|#| ; \
		 /PC_FILES/s|$${LIB_INSTALL_DIR}|libdata|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/doc/CMakeLists.txt

pre-configure-PYTHON-on:
	@${MKDIR} ${WRKDIR}/include/${PYTHON_VERSION}
	@${FIND} ${PYTHON_INCLUDEDIR} ! -name "pyport.h" -type f \
		-maxdepth 1 | ${XARGS} -J % ${LN} -sf % \
		${WRKDIR}/include/${PYTHON_VERSION}
	@${SED} -e 's|^#ifdef _PY_PORT_CTYPE_UTF8_ISSUE|#if 0|' \
		${PYTHON_INCLUDEDIR}/pyport.h > \
		${WRKDIR}/include/${PYTHON_VERSION}/pyport.h

.include <bsd.port.mk>
