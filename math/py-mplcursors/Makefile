PORTNAME=	mplcursors
DISTVERSION=	0.7.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive data selection cursors for Matplotlib
WWW=		https://mplcursors.readthedocs.io/en/stable/ \
		https://github.com/anntzer/mplcursors

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.1:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} MPLBACKEND=agg PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -W "ignore::RuntimeWarning" # upstream turns warnings into errors

# tests as of 0.7.1: 84 passed in 11.04s

.include <bsd.port.mk>
