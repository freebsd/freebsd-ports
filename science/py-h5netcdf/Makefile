PORTNAME=	h5netcdf
DISTVERSION=	1.8.3
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	netCDF4 via h5py
WWW=		https://h5netcdf.org \
		https://github.com/h5netcdf/h5netcdf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5pyd>=1.0.0:science/py-h5pyd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>0:science/py-netCDF4@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload

# tests as of 1.8.3: 324 passed, 215 skipped, 3 xfailed, 17 xpassed, 27 warnings in 2.60s

.include <bsd.port.mk>
