PORTNAME=	spreg
PORTVERSION=	1.9.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PySAL Spatial Econometrics Package
WWW=		https://spreg.readthedocs.io/en/latest/ \
		https://github.com/pysal/spreg

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpysal>=4.12:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.3,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.5:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.14:science/py-scipy@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bokeh>=0:www/py-bokeh@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}folium>=0:www/py-folium@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}geojson>=0:devel/py-geojson@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}geopandas>=1.1:graphics/py-geopandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=3.10:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numba>=0.60:devel/py-numba@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numexpr>=0:math/py-numexpr@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}seaborn>=0:math/py-seaborn@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}statsmodels>=0:math/py-statsmodels@${PY_FLAVOR}

.include <bsd.port.mk>
