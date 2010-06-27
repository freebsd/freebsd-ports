# New ports collection makefile for:   avogadro
# Date created:        19 May 2009
# Whom:                Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	avogadro
PORTVERSION=	1.0.0
PORTREVISION=	2
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

OPTIONS=	PYTHON "Enable python support (broken with sip-4.10)" off

.include <bsd.port.options.mk>

.if defined (WITH_PYTHON)
IGNORE=		doesn't compile with devel/py-sip>=4.10
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

.include <bsd.port.post.mk>
