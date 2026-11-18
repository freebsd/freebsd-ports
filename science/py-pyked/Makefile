PORTNAME=	pyked
DISTVERSION=	0.6.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for manipulating Chemical Kinetics Experimental Data files
WWW=		https://pr-omethe-us.github.io/PyKED/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cerberus>0:devel/py-cerberus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}habanero>=2.9.1:www/py-habanero@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx2>=2.0:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.24.0:devel/py-pint@${PY_FLAVOR} \
		rdkit>=2024.09.1:science/rdkit \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.2:math/py-uncertainties@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

TEST_ARGS=	--disable-plugin-autoload \
		--ignore=tests/test_live_api.py \
		-k "not test_doi_missing_internet and not test_orcid_missing_internet"

# tests as of 0.6.0: 1263 passed, 4 skipped, 3 deselected, 15 warnings in 147.20s

.include <bsd.port.mk>
