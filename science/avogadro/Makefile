# Created by: Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
# $FreeBSD$

PORTNAME=	avogadro
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced molecular editor and viewer

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2
LIB_DEPENDS=	openbabel:${PORTSDIR}/science/openbabel

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_GL=		glu
USE_QT4=	gui network opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DENABLE_GLSL=OFF \
		-DQT_MKSPECS_RELATIVE=share/qt4/mkspecs
USE_LDCONFIG=	yes

CFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		avogadro.1 avopkg.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ARGS+=	-DENABLE_PYTHON=ON
USE_PYTHON=	-2.7
BUILD_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sip>0:${PORTSDIR}/devel/py-sip
LIB_DEPENDS+=	boost_python:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sip>0:${PORTSDIR}/devel/py-sip
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_PYTHON=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/FLAGS_RELEASE/s|^|#| ; \
		 /PC_FILES/s|$${LIB_INSTALL_DIR}|libdata|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
