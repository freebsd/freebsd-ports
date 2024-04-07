PORTNAME=	arviz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	math python
#MASTER_SITES=	PYPI # missing test files
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for exploratory analysis of Bayesian models
WWW=		https://arviz-devs.github.io/arviz/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dm-tree>=0.1.8:devel/py-dm-tree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.5:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>=1.0.2:science/py-netCDF4@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.5.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.9.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2022.6.0:devel/py-xarray@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray-einstats>=0.3:devel/py-xarray-einstats@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}
#		${PYTHON_PKGNAMEPREFIX}pyro>0:devel/py-pyro@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests have 13 warnings, 1 error, see https://github.com/arviz-devs/arviz/issues/2084

USE_GITHUB=	yes
GH_ACCOUNT=	arviz-devs

NO_ARCH=	yes

.include <bsd.port.mk>
