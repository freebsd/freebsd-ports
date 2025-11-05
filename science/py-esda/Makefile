PORTNAME=	esda
PORTVERSION=	2.8.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Exploratory Spatial Data Analysis
WWW=		https://pysal.org/esda/ \
		https://github.com/pysal/esda

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geopandas>=0.14:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.12:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.1,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.4:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.12:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=2.1:devel/py-shapely@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.8:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numba>=0.58:devel/py-numba@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rtree>=1.1:devel/py-rtree@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}seaborn>=0.12:math/py-seaborn@${PY_FLAVOR}

.include <bsd.port.mk>
