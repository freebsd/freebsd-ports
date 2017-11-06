# $FreeBSD$

PORTNAME=	PyWavelets
PORTVERSION=	0.5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Discrete Wavelet Transforms in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		cython:lang/cython \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow
RUN_DEPENDS=	${PYNUMPY} \
		cython:lang/cython \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow

USE_GITHUB=	yes
GH_PROJECT=	pywt

USES=		cpe python
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

.include <bsd.port.mk>
