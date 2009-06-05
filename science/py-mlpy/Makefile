# New ports collection makefile for:	py-mlpy
# Date created:		18 April, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mlpy
PORTVERSION=	2.0.3
CATEGORIES=	science python
MASTER_SITES=	https://mlpy.fbk.eu/download/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MLPY-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	High performance Python package for predictive modeling

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gsl.13:${PORTSDIR}/math/gsl

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	MLPY

.include <bsd.port.mk>
