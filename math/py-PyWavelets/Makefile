# $FreeBSD$

PORTNAME=	PyWavelets
PORTVERSION=	0.5.2
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Discrete Wavelet Transforms in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PY_PILLOW}

USE_GITHUB=	yes
GH_PROJECT=	pywt

USES=		cpe python
USE_PYTHON=	autoplist distutils cython cython_run

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

.include <bsd.port.mk>
