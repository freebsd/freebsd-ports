# New ports collection makefile for:   avogadro
# Date created:        19 May 2009
# Whom:                Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	avogadro
PORTVERSION=	1.0.1
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	An advanced molecular editor and viewer

BUILD_DEPENDS=	eigen>=2.0.3:${PORTSDIR}/math/eigen2
LIB_DEPENDS=	openbabel.3:${PORTSDIR}/science/openbabel

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui opengl network linguist_build \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX="${PREFIX}" \
		-DLIB_INSTALL_DIR="${LOCALBASE}/lib" \
		-DENABLE_GLSL=OFF
USE_GCC=	4.4+
MAKE_JOBS_SAFE=	yes

OPTIONS=	PYTHON "Enable python support" off

MAN1=		avogadro.1 avopkg.1

.include <bsd.port.options.mk>

.if defined (WITH_PYTHON)
CMAKE_ARGS+=	-DENABLE_PYTHON=ON
USE_PYTHON=	2.5+
BUILD_DEPENDS+=	${PYNUMPY} \
		sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS+=	${PYNUMPY} \
		sip:${PORTSDIR}/devel/py-sip
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
