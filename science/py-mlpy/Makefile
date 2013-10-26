# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mlpy
PORTVERSION=	2.2.2
PORTREVISION=	3
CATEGORIES=	science python
MASTER_SITES=	https://mlpy.fbk.eu/download/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MLPY-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	High performance Python package for predictive modeling

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		cython>0:${PORTSDIR}/lang/cython
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl

CFLAGS+=	-I${LOCALBASE}/include -I${PYTHON_SITELIBDIR}/numpy/core
LDFLAGS+=	-L${LOCALBASE}/lib
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	MLPY

NO_STAGE=	yes
.include <bsd.port.mk>
