PORTNAME=	tobler
PORTVERSION=	0.13.0
PORTREVISION=	4
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Areal Interpolation
WWW=		https://pysal.org/tobler/ \
		https://github.com/pysal/tobler

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geopandas>=1.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1.4:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.10:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rasterio>=1.4:graphics/py-rasterio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rasterstats>=0.20:graphics/py-rasterstats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13,1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.14:math/py-statsmodels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67:misc/py-tqdm@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=0,2:astro/py-astropy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dask-geopandas>=0:devel/py-dask-geopandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}h3>=0:graphics/py-h3@${PY_FLAVOR}

.include <bsd.port.mk>
