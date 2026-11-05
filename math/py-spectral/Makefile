PORTNAME=	spectral
DISTVERSION=	0.26
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spectral Python is a Python module for hyperspectral image processing
WWW=		https://www.spectralpython.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} QT_QPA_PLATFORM=offscreen
TEST_WRKSRC=	${WRKSRC}
TEST_ARGS=	--disable-plugin-autoload \
		spectral/tests/test_ndwindow.py \
		spectral/tests/test_status.py \
		spectral/tests/test_resampling.py

# tests as of 0.26: 82 passed, 1 skipped (ndwindow, status, resampling; spyfile/database require external data)

.include <bsd.port.mk>
