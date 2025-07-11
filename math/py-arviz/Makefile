PORTNAME=	arviz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22.0
CATEGORIES=	math python
#MASTER_SITES=	PYPI # missing test files
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for exploratory analysis of Bayesian models
WWW=		https://python.arviz.org/en/stable/ \
		https://github.com/arviz-devs/arviz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dm-tree>=0.1.8:devel/py-dm-tree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.8:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.1.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5netcdf>=1.0.2:science/py-h5netcdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2023.7.0:devel/py-xarray@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray-einstats>=0.3:devel/py-xarray-einstats@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}
#		${PYTHON_PKGNAMEPREFIX}pyro>0:devel/py-pyro@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	arviz-devs

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		DISPLAY=${DISPLAY} \
		XAUTHORITY=${XAUTHORITY}

# tests as of 0.22.0: 2930 passed, 30 skipped, 128 warnings, 613 errors in 1228.57s (0:20:28), see https://github.com/arviz-devs/arviz/issues/2462

.include <bsd.port.mk>
