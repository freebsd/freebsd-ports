PORTNAME=	arviz-stats
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Statistical computation and diagnostics for ArviZ
WWW=		https://python.arviz.org/projects/stats/en/latest/ \
		https://github.com/arviz-devs/arviz-stats

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arviz-base>=1.0.0:math/py-arviz-base@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray-einstats>=0:devel/py-xarray-einstats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2024.11.0:devel/py-xarray@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5netcdf>0:science/py-h5netcdf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	arviz-devs

NO_ARCH=	yes

TEST_ARGS=	-p no:benchmark -p no:xdist -p no:relaxed
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.0.0: 2449 passed, 5 skipped, 9 warnings in 47.13s

.include <bsd.port.mk>
