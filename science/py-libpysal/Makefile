PORTNAME=	libpysal
PORTVERSION=	4.13.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core components of PySAL A library of spatial analysis functions
WWW=		https://pysal.org/libpysal/ \
		https://github.com/pysal/libpysal

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.10:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=0.10.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.4,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.0.2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.8:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.0.1:devel/py-shapely@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}joblib>=1.2:devel/py-joblib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}networkx>=2.7:math/py-networkx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numba>=0.55:devel/py-numba@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyarrow>=7.0:databases/py-pyarrow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xarray>=2022.3:devel/py-xarray@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zstd>=0:archivers/py-zstd@${PY_FLAVOR}

.include <bsd.port.mk>
