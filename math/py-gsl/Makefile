# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	gsl
PORTVERSION=	0.9.5
PORTREVISION=	7
CATEGORIES=	math python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygsl-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python interface to GNU Scientific Library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/include/numpy/arrayobject.h:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/__init__.py:${PORTSDIR}/math/py-numpy
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
