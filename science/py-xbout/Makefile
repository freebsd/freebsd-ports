PORTNAME=	xbout
DISTVERSION=	0.3.8
CATEGORIES=	science education
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collect data from BOUT++ runs in python using xarray
WWW=		https://github.com/boutproject/xBOUT

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}animatplot-ng>=0.4.2:math/py-animatplot-ng@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boutdata>=0.1.4:science/py-boutdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=2.10.0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gelidum>=0.5.3:devel/py-gelidum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.1.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=5.5.0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>=1.4.0:science/py-netCDF4@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2023.01.0:devel/py-xarray@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/xbout/tests

.include <bsd.port.mk>
