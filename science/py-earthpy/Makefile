PORTNAME=	earthpy
PORTVERSION=	0.9.4
PORTREVISION=	5
CATEGORIES=	science geography python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Plot and manipulate spatial data in Python
WWW=		https://github.com/earthlab/earthpy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}rasterio>=0:graphics/py-rasterio@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}geopandas>=0:graphics/py-geopandas@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0:graphics/py-scikit-image@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}rasterio>=0:graphics/py-rasterio@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}geopandas>=0:graphics/py-geopandas@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0:graphics/py-scikit-image@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils

.include <bsd.port.mk>
