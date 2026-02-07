PORTNAME=	xbout
DISTVERSION=	0.3.5
PORTREVISION=	4
CATEGORIES=	science education
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collect data from BOUT++ runs in python using xarray
WWW=		https://github.com/boutproject/xBOUT

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}animatplot>=0.4.2:math/py-animatplot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boutdata>=0.1.4:science/py-boutdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=2.10.0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gelidum>=0.5.3:devel/py-gelidum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.1.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=5.5.0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>=1.4.0:science/py-netCDF4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=6.1.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=0.18.0:devel/py-xarray@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/xbout/tests

.include <bsd.port.mk>
