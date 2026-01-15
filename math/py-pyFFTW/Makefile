PORTNAME=	pyFFTW
DISTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pythonic wrapper around FFTW, the FFT library
WWW=		https://hgomersall.github.io/pyFFTW/ \
		https://github.com/pyFFTW/pyFFTW

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}dask>=1.0.0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2.0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python localbase:ldflags
USE_PYTHON=	autoplist cython distutils pytest # tests fail with "attempted relative import with no known parent package", see https://github.com/pyFFTW/pyFFTW/issues/405

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyfftw/pyfftw${PYTHON_TAG}.so

.include <bsd.port.mk>
