PORTNAME=	libpysal
PORTVERSION=	4.15.0
PORTREVISION=	1
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.13.0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=1.1.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.3.0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.3:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.5.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.14.0,1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.1:devel/py-shapely@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}joblib>=1.5.0:devel/py-joblib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}networkx>=3.4,2:math/py-networkx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numba>=0.60:devel/py-numba@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandarm>=0:graphics/py-pandarm@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pulp>=0:math/py-PuLP@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyarrow>=16.1:databases/py-pyarrow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xarray>=2024.5:devel/py-xarray@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zstd>=0:archivers/py-zstd@${PY_FLAVOR}

.include <bsd.port.mk>
