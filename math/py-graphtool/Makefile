# Created by: dikshie <dikshie@sfc.wide.ad.jp>
# $FreeBSD$

PORTNAME=	graphtool
PORTVERSION=	2.2.12
PORTREVISION=	5
CATEGORIES=	math python
MASTER_SITES=	http://downloads.skewed.de/graph-tool/
DISTNAME=	graph-tool-${PORTVERSION}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Python module for complex network based on C++

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.8.0:${PORTSDIR}/science/py-scipy
LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libboost_graph.so:${PORTSDIR}/devel/boost-libs \
		libCGAL.so:${PORTSDIR}/math/cgal

USE_BZIP2=	yes
USE_GCC=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	PYTHON_VERSION=${PYTHON_VER}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

BROKEN=                fails to build

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: exhausts virtual memory
.endif

.include <bsd.port.post.mk>
