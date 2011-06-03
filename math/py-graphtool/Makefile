# New ports collection makefile for:	py-graphtool
# Date created:		2011-04-29
# Whom:			dikshie <dikshie@sfc.wide.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	graphtool
PORTVERSION=	2.2.12
CATEGORIES=	math python
MASTER_SITES=	http://downloads.skewed.de/graph-tool/
DISTNAME=	graph-tool-${PORTVERSION}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Python module for complex network based on C++

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib
LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs \
		boost_graph.4:${PORTSDIR}/devel/boost-libs \
		CGAL.5:${PORTSDIR}/math/cgal

USE_BZIP2=	yes
USE_GCC=	4.5+
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
