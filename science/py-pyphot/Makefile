PORTNAME=	pyphot
DISTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computing photometry from spectra
WWW=		https://mfouesneau.github.io/pyphot/ \
		https://github.com/mfouesneau/pyphot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>5.0:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=3.14.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.3.3:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0.9:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tables>0:devel/py-tables@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	-p no:ruff unittests

NO_ARCH=	yes

# tests as of 2.1.1:
# Results (19.55s):
#    1420 passed
#      14 skipped

.include <bsd.port.mk>
