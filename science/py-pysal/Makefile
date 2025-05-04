PORTNAME=	pysal
PORTVERSION=	24.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library of spatial analysis functions
WWW=		https://pysal.org/ \
		https://github.com/pysal/pysal/releases

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Depends on expired math/py-spvcm
EXPIRATION_DATE=2025-06-04

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}access>=1.1.8:science/py-access@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}esda>=2.4.1:science/py-esda@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}giddy>=2.3.3:graphics/py-giddy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inequality>=1.0.0:science/py-inequality@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.6.2:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mapclassify>=2.4.3:graphics/py-mapclassify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mgwr>=2.1.2:graphics/py-mgwr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}momepy>=0.5.3:graphics/py-momepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pointpats>=2.2.0:graphics/py-pointpats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}segregation>=2.3.1:science/py-segregation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spaghetti>=1.6.6:science/py-spaghetti@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglm>=1.0.8:math/py-spglm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spint>=1.0.7:math/py-spint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}splot>=1.1.5.post1:math/py-splot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spopt>=0.4.1:math/py-spopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spreg>=1.2.4:math/py-spreg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spvcm>=0.3.0:math/py-spvcm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tobler>=0.8.2:science/py-tobler@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PLUS
PLUS_DESC=	Extra features

PLUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bokeh>=0.11.1:www/py-bokeh@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}descartes>=0:graphics/py-descartes@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}folium>=0.2.1:www/py-folium@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}geojson>=1.3.2:devel/py-geojson@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}geopandas>=0.2:graphics/py-geopandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mapclassify>=0:graphics/py-mapclassify@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.1:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numba>=0:devel/py-numba@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numexpr>=0:math/py-numexpr@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}palettable>=0:misc/py-palettable@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandana>=0:graphics/py-pandana@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.17.1:science/py-scikit-learn@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}seaborn>=0.7.0:math/py-seaborn@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}statsmodels>=0.6.1:math/py-statsmodels@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}urbanaccess>=0:graphics/py-urbanaccess@${PY_FLAVOR}

.include <bsd.port.mk>
