PORTNAME=	galore
DISTVERSION=	0.10.0
CATEGORIES=	science python # chemistry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Broadening and weighting for simulated spectra
WWW=		https://github.com/SMTG-Bham/galore

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymatgen>0:science/py-pymatgen@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist unittest
USE_GITHUB=	yes
GH_ACCOUNT=	SMTG-Bham

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	discover test

# tests as of 0.10.0: Ran 41 tests, OK (skipped=5)

.include <bsd.port.mk>
