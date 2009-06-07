# New ports collection makefile for:   avogadro
# Date created:        19 May 2009
# Whom:                Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	avogadro
PORTVERSION=	0.9.6
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	An advanced molecular editor and viewer

BUILD_DEPENDS=	eigen>=2.0.0:${PORTSDIR}/math/eigen2 \
		${PYNUMPY} \
		sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PYNUMPY} \
		sip:${PORTSDIR}/devel/py-sip
LIB_DEPENDS=	openbabel.3:${PORTSDIR}/science/openbabel \
		boost_python:${PORTSDIR}/devel/boost-python

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui opengl linguist qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX="${PREFIX}" -DLIB_INSTALL_DIR="${LOCALBASE}/lib"
USE_GCC=	4.3+
USE_PYTHON=	2.5+
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700013
BROKEN=		requires posix_memalign
.endif

.include <bsd.port.post.mk>
