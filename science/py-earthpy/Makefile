PORTNAME=	earthpy
PORTVERSION=	1.0.0
CATEGORIES=	science geography python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Plot and manipulate spatial data in Python
WWW=		https://github.com/earthlab/earthpy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}keyring>=0:security/py-keyring@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}rasterio>=0:graphics/py-rasterio@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}geopandas>=0:graphics/py-geopandas@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0:graphics/py-scikit-image@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}keyring>=0:security/py-keyring@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}rasterio>=0:graphics/py-rasterio@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}geopandas>=0:graphics/py-geopandas@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0:graphics/py-scikit-image@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517

.include <bsd.port.mk>
