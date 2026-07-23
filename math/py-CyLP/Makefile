PORTNAME=	CyLP
DISTVERSIONPREFIX=	v
DISTVERSION=	0.94.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to CLP, CBC, and CGL to solve LPs and MIPs
WWW=		https://github.com/coin-or/CyLP

LICENSE=	CPL10
LICENSE_NAME=	Common Public License Version 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libblas.so:math/blas \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libCoinUtils.so:math/coinutils \
		liblapack.so:math/lapack \
		libOsi.so:math/osi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.10.0:science/py-scipy@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist cython pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or

MAKE_ENV=	COIN_INSTALL_DIR=${LOCALBASE}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	# deselect tests:
	# * test_PySolve.py: it SEGVs, see https://github.com/coin-or/CyLP/issues/232
	# * test_removeVar2: it fails with Python error, see https://github.com/coin-or/CyLP/issues/231
	@cd ${WRKDIR} && ${SETENV} ${TEST_ENV} pytest -rs --pyargs cylp \
		--ignore=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cylp/py/test_PySolve.py \
		-k 'not test_removeVar2'

# tests as of 0.94.0: 12 passed, 1 deselected, 36 warnings in 0.20s

.include <bsd.port.mk>
