PORTNAME=	nglview
DISTVERSION=	4.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IPython widget to view molecular structures and trajectories
WWW=		http://nglviewer.org/nglview/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>=0.7.9:devel/py-jupyter-packaging@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipywidgets>=8:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=3:devel/py-jupyterlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-widgets>0:devel/py-jupyterlab-widgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook>=7:www/py-notebook@${PY_FLAVOR} \
		${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 28 tests fail because of missing test dependencies

NO_ARCH=	yes

.include <bsd.port.mk>
