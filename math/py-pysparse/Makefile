# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pysparse
PORTVERSION=	1.3
PORTREVISION=	10
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast sparse matrix library for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.2,1:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.2,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libopenblas.so:math/openblas

USE_GITHUB=	yes
GH_ACCOUNT=	PythonOptimizers
GH_TAGNAME=	f8430bd

LDFLAGS+=	-shared  # Workaround for an obscure bug in py-numpy, see https://github.com/numpy/numpy/issues/7779

USES=		fortran python:2.7 # fortran is needed for the correct build flags passed to py-numpy extension build process
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
