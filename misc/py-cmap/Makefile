PORTNAME=	cmap
DISTVERSION=	0.3.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific colormaps for python, without dependencies
WWW=		https://cmap-docs.readthedocs.io/en/stable/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bokeh>0:www/py-bokeh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorspacious>0:devel/py-colorspacious@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colour>0:graphics/py-colour@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>0:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-extra-types>=2:devel/py-pydantic-extra-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyqtgraph>0:graphics/py-pyqtgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-qt>0:devel/py-pytest-qt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vispy>=0.14:graphics/py-vispy@${PY_FLAVOR}
		# TEST_DEPENDS also needs napari, pygfx, viscm

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 3 tests fail because the $DISPLAY variable is missing

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
