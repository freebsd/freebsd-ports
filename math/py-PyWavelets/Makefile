# $FreeBSD$

PORTNAME=	PyWavelets
PORTVERSION=	0.5.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Discrete Wavelet Transforms in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow@${FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow@${FLAVOR}

USE_GITHUB=	yes
GH_PROJECT=	pywt

USES=		cpe python:2.7
USE_PYTHON=	autoplist distutils cython cython_run

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

.include <bsd.port.mk>
