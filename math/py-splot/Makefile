PORTNAME=	splot
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Visual analytics for spatial analysis with PySAL
WWW=		https://splot.readthedocs.io/en/latest/ \
		https://github.com/pysal/splot

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}esda>=0:science/py-esda@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geopandas>=0.9.0:graphics/py-geopandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}giddy>=0:graphics/py-giddy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=0:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mapclassify>=0:graphics/py-mapclassify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.3.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seaborn>=0.11.0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spreg>=0:math/py-spreg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
