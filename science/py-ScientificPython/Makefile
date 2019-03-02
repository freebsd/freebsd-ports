# $FreeBSD$

PORTNAME=	ScientificPython
DISTVERSION=	2.9.4
PORTREVISION=	3
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Various Python modules for scientific computing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libnetcdf.so:science/netcdf
RUN_DEPENDS=	${PYNUMPY}

USES=		python:2.7
USE_PYTHON=	distutils cython concurrent autoplist

MAKE_ENV=	COMPILE_CYTHON=1

.include <bsd.port.mk>
