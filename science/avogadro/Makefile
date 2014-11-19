# Created by: Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
# $FreeBSD$

PORTNAME=	avogadro
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced molecular editor and viewer

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	eigen2>2:${PORTSDIR}/math/eigen2
LIB_DEPENDS=	libopenbabel.so:${PORTSDIR}/science/openbabel

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

USES=		cmake desktop-file-utils pkgconfig tar:bzip2
USE_GL=		glu gl
USE_QT4=	gui network opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DENABLE_GLSL=OFF \
		-DQT_MKSPECS_RELATIVE=share/qt4/mkspecs
USE_LDCONFIG=	yes

CFLAGS+=	-idirafter ${LOCALBASE}/include/eigen2 \
		-idirafter ${LOCALBASE}/include \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2
BUILD_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sip>0:${PORTSDIR}/devel/py-sip
LIB_DEPENDS+=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sip>0:${PORTSDIR}/devel/py-sip
CMAKE_ARGS+=	-DENABLE_PYTHON=ON \
		-DPYTHON_INCLUDE_DIR:PATH=${WRKDIR}/include/${PYTHON_VERSION}
.else
CMAKE_ARGS+=	-DENABLE_PYTHON=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/FLAGS_RELEASE/s|^|#| ; \
		 /PC_FILES/s|$${LIB_INSTALL_DIR}|libdata|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/doc/CMakeLists.txt

pre-configure:
.if ${PORT_OPTIONS:MPYTHON}
	@${MKDIR} ${WRKDIR}/include/${PYTHON_VERSION}
	@${FIND} ${PYTHON_INCLUDEDIR} ! -name "pyport.h" -type f \
		-maxdepth 1 | ${XARGS} -J % ${LN} -sf % \
		${WRKDIR}/include/${PYTHON_VERSION}
	@${SED} -e 's|^#ifdef _PY_PORT_CTYPE_UTF8_ISSUE|#if 0|' \
		${PYTHON_INCLUDEDIR}/pyport.h > \
		${WRKDIR}/include/${PYTHON_VERSION}/pyport.h
.endif

.include <bsd.port.mk>
