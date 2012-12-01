# Created by: Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
# $FreeBSD$

PORTNAME=	avogadro
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	Advanced molecular editor and viewer

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2
LIB_DEPENDS=	openbabel.3:${PORTSDIR}/science/openbabel

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GL=		glu
USE_QT4=	gui opengl network linguist_build \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
CMAKE_ARGS=	-DENABLE_GLSL=OFF \
		-DQT_MKSPECS_RELATIVE=share/qt4/mkspecs
USE_GCC=	4.4+
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	PYTHON

MAN1=		avogadro.1 avopkg.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ARGS+=	-DENABLE_PYTHON=ON
USE_PYTHON=	-2.7
BUILD_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sip>0:${PORTSDIR}/devel/py-sip
RUN_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sip>0:${PORTSDIR}/devel/py-sip
LIB_DEPENDS+=	boost_python:${PORTSDIR}/devel/boost-python-libs
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_PYTHON=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700013
BROKEN=		requires posix_memalign
.endif

post-patch:
	@${REINPLACE_CMD} 's|share/man|man|' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.post.mk>
