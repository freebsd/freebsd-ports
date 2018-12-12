# $FreeBSD$

PORTNAME=	pyFFTW
DISTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pythonic wrapper around FFTW, the FFT library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float
RUN_DEPENDS=	${PYNUMPY}

USES=		python localbase:ldflags
USE_PYTHON=	distutils cython autoplist

.include <bsd.port.mk>
