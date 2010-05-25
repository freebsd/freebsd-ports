# New ports collection makefile for:	py-gsl
# Date created:		14 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	0.9.5
CATEGORIES=	math python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygsl-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python interface to GNU Scientific Library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/include/numpy/arrayobject.h:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/__init__.py:${PORTSDIR}/math/py-numpy
LIB_DEPENDS=	gsl.15:${PORTSDIR}/math/gsl

PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pygsl

.include <bsd.port.mk>
