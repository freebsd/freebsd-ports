PORTNAME=	pysal
PORTVERSION=	25.7
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Meta Package for PySAL - A library of spatial analysis functions
WWW=		https://pysal.org/pysal/ \
		https://github.com/pysal/pysal

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}access>=1.1.9:science/py-access@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.10:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}esda>=2.7.1:science/py-esda@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=0.10.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}giddy>=2.3.6:graphics/py-giddy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inequality>=1.1.2:science/py-inequality@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.13.0:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mapclassify>=2.10.0:graphics/py-mapclassify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mgwr>=2.2.1:graphics/py-mgwr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}momepy>=0.10.0:graphics/py-momepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.4:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.0.2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pointpats>=2.5.1:graphics/py-pointpats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.8,1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}segregation>=2.5.2:science/py-segregation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.0.1:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spaghetti>=1.7.6:science/py-spaghetti@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglm>=1.1.0:math/py-spglm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spint>=1.0.7:math/py-spint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}splot>=1.1.7:math/py-splot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spopt>=0.7.0:math/py-spopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spreg>=1.8.3:math/py-spreg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tobler>=0.12.1:science/py-tobler@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}joblib>=1.2:devel/py-joblib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}networkx>=2.7,2:math/py-networkx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numba>=0.55:devel/py-numba@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyarrow>=7.0:databases/py-pyarrow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xarray>=2022.3:devel/py-xarray@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zstd>=0:archivers/py-zstd@${PY_FLAVOR}

.include <bsd.port.mk>
